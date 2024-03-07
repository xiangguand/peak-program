#!/usr/bin/bash

echo "Script run on machine \"$(uname -m)\""

make clean
make all

./unit_test 
if [ $? -eq 0 ]; then
  echo "Unit test passed"
else
  echo "Unit test fail"
  exit -1
fi

echo "============= cat test.txt ============="
cat test.txt
echo ""
echo "=================================="
echo "Running peak test, \"./peak 80 test.txt\""
./peak 80 test.txt
if [ $? -eq 0 ]; then
  echo "Test passed"
else
  echo "Test failed"
  exit -1
fi


echo "Running peak test, \"./peak 40 test.txt\""
./peak 40 test.txt
if [ $? -eq 0 ]; then
  echo "Test passed"
else
  echo "Test failed"
  exit -1
fi


echo "Running peak test, \"./peak 64 test.txt\""
./peak 64 test.txt
if [ $? -eq 0 ]; then
  echo "Test passed"
else
  echo "Test failed"
  exit -1
fi

echo "Test script exit successfully"

