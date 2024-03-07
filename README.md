# VICI Holding interview
author: Xiang-Guan Deng (Danny Deng)  
Only for VICI Holding Interview

## Build code via linux environment using docker tool
### Build docker image
```bash
docker build -t vici_demo .
```

### Run image
```bash
docker run -d --name "demo" vici_demo
```

### Get into docker environment
```bash
docker exec -it demo bash
```

## How to build code
### How to build peak program and unit_test program
```bash
cd /home/demo
make all
```
### Simply use via executing script runtest.sh
```bash
./peak 80 test.txt
```
### Simply use via executing script runtest.sh
```bash
./runtest.sh
```
### How to install to your Linux
```bash
make install
```
### How to uninstall to your Linux
```bash
make uninstall
```

