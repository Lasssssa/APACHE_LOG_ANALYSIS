#!/bin/bash

echo "Test ID;Return code validation;Out result;StdErr result;File creation result;Global result" > results.csv
nOk=0
nKo=0
nTotal=0
nMis=0

for i in Test*; do
  ./test.sh "$i" results.csv
  result=$?

  if [ $result -eq 0 ]; then
    ((nKo++))
  elif [ $result -eq 1 ]; then
    ((nOk++))
  else
    ((nMis++))
  fi

  ((nTotal++))
done

echo "Passed tests     : $nOk"
echo "Failed tests     : $nKo"
echo "Misformed tests  : $nMis"
echo "-----------------------"
echo "Total            : $nTotal"
