#!/bin/bash

echo "[TESTING]"
echo "----------------------------------------------------------------------"
echo ""

build/executable/./cas.out /frac{3}{4}
echo ""

build/executable/./cas.out /frac{/sin{3}}{4}
echo ""

build/executable/./cas.out /sin{/cos{3}}
echo ""

echo "----------------------------------------------------------------------"
echo "[COMPLETE]"