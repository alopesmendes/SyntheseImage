
# <center> SyntheseImage : RayTracing
### Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien

# Introduction
Ray tracing is a rendering technique for generating an image by tracing the path of light as pixels in an image plane and simulating the effects of its encounters with virtual objects. This technique will produce a high degree of visual realism.
# Installation
```sh
/SyntheseImage/Kit.M1.M2.2020$  chmod a+x install.sh
/SyntheseImage/Kit.M1.M2.2020$  cd libg2x
/SyntheseImage/Kit.M1.M2.2020/libg2x$ make
/SyntheseImage/Kit.M1.M2.2020$  cd libg3x
/SyntheseImage/Kit.M1.M2.2020/libg3x$ make
```
# Usage

| opt | description |
| ------ | ------ |
| -n | 1 to 3 |
| -i | input file format .txt |
| -o | output file format .ppm |
| -ps | number of rays > 0 |

### Exemple

```sh
/SyntheseImage/Kit.M1.M2.2020$  cd 3D
/SyntheseImage/Kit.M1.M2.2020/3D$  make
/SyntheseImage/Kit.M1.M2.2020/3D$  ./lray -n 1 -i input/sphere.txt -o image.ppm
/SyntheseImage/Kit.M1.M2.2020/3D$  ./lray -n 3 -i input/sphere.txt -o i64.ppm -ps 64
```

# UML 
![UML](https://www.plantuml.com/plantuml/img/XLRVRzem47xFNt5FA6b3jETDHMLTro9HXcWtQT9UtCGbre8TsGujhVg_p_Ov9cQCmODzv-z--lF1fT94wcxJ94dP4ALWIQIY4juIC9ytSwfP-JxsMiQPJXdNGEIwpA6iYOIpCoDiSr1QChu6qMgLnSPRmIeWLVKWxalAQNgl2Q-8hBwoTISfgATWN55LIjPg9dWE3Zm2PPVOuxaxWjObTJoVB7bF4igx3Hn4my9cYn_J-UnBZiBTzEOQjrVJk-lL5FVpsStj0sxlbxVNgnxo_RFVFQncqyNDt4lB-NJHGxw5tS_vRF7bUeNInOLRpWzIabI9PajZRUfRmdZRQLSDtW-MZbKK1Lm9Re1TgOKqedVlkfn58Vixk28RAacA2vHkoMB8VKtQevTqO1HIylgJEVcuFwZJjaBbuFU6VskgSwX4zzXGq3NL94XjpSA-OafdaRUun9uTU7W6fQH4XpuEgEMThCWEDkGtDMjQsfJ1CcdK6HxjfMqlpJPaRTZ8DeF2dUvqtGxYAFhCAbtdpcjDsRhMlUShqGWvCe9Pu0B5z4DklbasT7BaGXNLI_P26nVW1PtlSdI13hEuDyxJ_rlJmp48sTBqe0bcwTD79oDuOWrrlU52KsZeamRn18vCy17k2D-1ie82ea2rDPN6HTiGJbLH5ByuVT6KLyeGW2aGd1OzuPs7KqqE122FveYK-dtGM33amfPccF1nx9tfXsIaiV1-_o-BHo4Qssfgna-fVMiCYqOWYUd-BTCZgDdmqNggdsGAOb9FzfT0-rtOlMOHCkQ3nwYID4GkfQYwa9gFFceZUqC2eLG46S4sYxnn8JS7JhQn4zEkXG6HXhtIAXqE1TVyqpF1NOiF9MaL2brBIdcG7fkEPaEBK7W8Pf_ooL3sZVkCXMHhniFugPWq6qlzJtjerDfz67EpfyCOWBSrWA-CDeRFyVtQqHV9t7Klwhedd2F-6JwQVGvpEpfEP-4WqQZrZYrdkM9wbms1nwUeE_l_f3XuOyYLuIztFoQYLv7uvCPsJ8md-COJz3MMDd9GukzTKObdNXG7IeUqMXpvlTewTTZe9opn_s7GrGIJ_4iPc_HfTkru7ABWr0yPHTgnrLeiUlSLsSy4XsTYgTf7ywP35TPdYLPqxRvWl7LVMJ4nvrxbKXjFCD4UPYsB2QPmQOQg-Nlt1m00)
