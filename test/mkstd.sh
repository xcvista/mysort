#!/bin/bash

sort -g > .mkstd
cat .mkstd | head -n1
cat .mkstd | tail -n1
rm .mkstd

