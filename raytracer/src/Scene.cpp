#include "../include/Scene.h"
#include "../include/GraphicWindow.h"
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <random>
#include <sstream>
#include <limits>
#include <omp.h>

Scene::Scene(int level, string file, string imName, int ps) {
    this->level = level;
    this->file = file;
    this->imageName = imName;
    this->ps = ps;
}

Scene::~Scene() {

}

void Scene::addCamera(const Camera &cam) {
    camera = cam;
}

void Scene::addShape(const StandardFigure &standardFigure, Shape* shape) {
    shapes[standardFigure].push_back(shape);
}

void Scene::addLight(const Light &l) {
    lights.push_back(l);
}

void Scene::addImage(const Image &im) {
    image = im;
}

const Camera Scene::getCam() const {
    return camera;
}

const bool Scene::intersectShadowRay(const Hit &hit) const{
    for (auto l = lights.begin(); l != lights.end(); ++l) {
        Vector v = l->getPos() - hit.pos;
        double d_light2 = v.scalarProduct(v);
        Ray rayLight = Ray(hit.pos + hit.normal*0.01, v.getNormalized());
        for (auto categorie = shapes.begin(); categorie != shapes.end(); ++categorie) {
            for (auto shape = categorie->second.begin(); shape != categorie->second.end(); ++shape) {
                Hit localHit;
                bool localItersect = (**shape).intersect(rayLight, localHit);
                if (localItersect && localHit.t*localHit.t <= d_light2) {
                    return true;
                }
            }
        }
    }
    return false;
}


const bool Scene::intersect(const Ray &ray, Hit &hit) const {
    bool hasItersect = false;
    hit.t = INFINITY;
    for (auto categorie = shapes.begin(); categorie != shapes.end(); ++categorie) {
        for (auto shape = categorie->second.begin(); shape != categorie->second.end(); ++shape) {
            Hit localHit;
            bool localItersect = (**shape).intersect(ray, localHit);
            if (localItersect) {
                hasItersect = true;
                if (localHit.t < hit.t) {
                    hit = localHit;
                }
            }
        }
    }
    return hasItersect;
}

void Scene::mirror(Color &c, const Ray &ray, const Hit &hit, int& nbonds) {
    Vector n = hit.normal;
    Vector dMirror = ray.getDirection().reflect(n);
    Ray rMirror = Ray(hit.pos + n*0.001, dMirror);
    c = traceRay(rMirror, nbonds--);
}

void Scene::transperecy(Color &c, const Ray &ray, const Hit &hit, int& nbonds) {
    Vector n = hit.normal;
    double n1 = 1, n2 = 1.3;
    Vector nt = hit.normal;
    if (n.scalarProduct(ray.getDirection()) > 0) {
        swap(n1, n2);
        nt = n * (-1);
    }
    double radical = 1 - pow(n1 / n2, 2)*(1 - pow(nt.scalarProduct(ray.getDirection()), 2));
    if (radical > 0) {
        Vector dirRef = (ray.getDirection() - nt * nt.scalarProduct(ray.getDirection())) * (n1/n2) - nt * sqrt(radical);
        Ray rayRef = Ray(hit.pos - nt*0.001, dirRef);
        c = traceRay(rayRef, nbonds--);
    }
}

Color Scene::traceRay(const Ray &ray, int nbonds) {
    if (nbonds <= 0) {
        return image.backgroundColor();
    }
    Hit hit, hitLight;
    Color c = image.backgroundColor();
    bool hasIter = intersect(ray, hit);
    
    if (hasIter) {
        if ( level == 3 && hit.shape->getMaterial().isMirror() ) {
            mirror(c, ray, hit, nbonds);
        } else {
            if ( level == 3 && hit.shape->getMaterial().isTransparent() ) {
                transperecy(c, ray, hit, nbonds);
            } else {
                // direct illumination
                c = hit.shape->getMaterial().ambience;
                if (level == 3) {
                    bool shadow =  intersectShadowRay(hit);
                    if (shadow == false) {
                        for (auto light = lights.begin(); light != lights.end(); light++) {
                            c += light->getColor((*this), camera, hit);
                        }
                    } 

                    // indirect illuminations
                    if (ps > 0) {
                        Vector dRandom = Vector::dRandom(hit.normal);
                        Ray rayRandom = Ray(hit.pos + hit.normal*0.001, dRandom);
                        c += hit.shape->getColor() * traceRay(rayRandom, nbonds - 1);
                    }
                } else {
                    for (auto light = lights.begin(); light != lights.end(); light++) {
                        c += light->getColor((*this), camera, hit);
                    }
                }
            }
        }
    }
    return c;
}


void Scene::render() {
    double fov = 60. * M_PI / 180.;

    #pragma omp parallel for
	for(int i = 0; i < image.getHeight(); ++i) {
		for(int j = 0; j < image.getWidth(); ++j) {
            /*Vector dir = Vector(
                j - image.getWidth() / 2.,
                i - image.getHeight() / 2.,
                -image.getWidth() / (2. * tan(fov / 2.))
            );
            dir.normalize();
            Ray ray = Ray(camera.getPos(), dir);*/
            Ray ray = camera.makeRay(i, j, image);
            Color c;
            int nrays = level == 3 && ps > 0 ? ps : 1;
            for (int k = 0; k < nrays; ++k) {
                c += traceRay(ray, 5) / nrays;
            }
            image.setPixel(i, j, c);
		}
	}
}

void Scene::buildImage() {
    Image::save(image, imageName);
    cout << "Saved image:" << imageName << endl;
}


void Scene::buildWindow() {
    GraphicWindow g(image.getWidth(), image.getHeight());
    bool quit = false;
    SDL_Event event;
    g.render(image, camera);
    static const map<SDL_Keycode, Coord> events = {
        {SDLK_DOWN, Coord(Vector(0., -10, 0.), Vector(), Vector(), 0., 0., 0., 0.)},
        {SDLK_RIGHT, Coord(Vector(10, 0., 0.), Vector(), Vector(), 0., 0., 0., 0.)},
        {SDLK_UP, Coord(Vector(0., 10, 0.), Vector(), Vector(), 0., 0., 0., 0.)},
        {SDLK_LEFT, Coord(Vector(-10, 10, 0.), Vector(), Vector(), 0., 0., 0., 0.)},
        {SDLK_i, Coord(Vector(), Vector(0., 10, 0.), Vector(), 0., 0., 0., 0.)},
        {SDLK_k, Coord(Vector(), Vector(0., -10, 0.), Vector(), 0., 0., 0., 0.)},
        {SDLK_j, Coord(Vector(), Vector(-10, 0., 0.), Vector(), 0., 0., 0., 0.)},
        {SDLK_l, Coord(Vector(), Vector(10, 0., 0.), Vector(), 0., 0., 0., 0.)},
        {SDLK_x, Coord(Vector(), Vector(), Vector(1., 0., 0.), 0., 0., 0., 0.)},
        {SDLK_y, Coord(Vector(), Vector(), Vector(0., 1., 0.), 0., 0., 0., 0.)},
        {SDLK_z, Coord(Vector(), Vector(), Vector(0., 0., 1.), 0., 0., 0., 0.)},
        {SDLK_KP_PLUS, Coord(Vector(), Vector(), Vector(), -10., 0., 0., 0.)},
        {SDLK_KP_MINUS, Coord(Vector(), Vector(), Vector(), 10., 0., 0., 0.)},
    };

    while (!quit) {
        SDL_WaitEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                quit = true;
                break;
            
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_s) {
                    buildImage();
                }
                auto itr = events.find(event.key.keysym.sym);
                if (itr != events.end()) {
                    camera = camera+ itr->second;
                    render();
                    g.render(image, camera);
                }
                break;
        }
    }
}

void Scene::build() {
    if (level == 2) {
        buildWindow();
    } else {
        buildImage();
    }
}

Scene::operator std::string() const {
    stringstream ss;
    ss << image << endl;
    ss << camera << endl;
    ss << "Lights {" << endl;
    for (auto i = lights.begin(); i != lights.end(); i++) {
        ss << '\t' << (*i) << endl;
    }
    ss << "}"<< endl;
    ss << "Shapes {" << endl;
    for (auto i = shapes.begin(); i != shapes.end(); ++i) {
        for (auto j = i->second.begin(); j != i->second.end(); ++j) {
            ss << '\t' << (**j) << endl;
        }   
    }
    ss << "}";
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Scene& scene) {
    string text = scene;
    os << text;
    return os;
}