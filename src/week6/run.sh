#!/bin/bass

python3 generator.py
./D_digitos < input.txt > output1.txt
./D_digitos_lento < input.txt > output2.txt
diff output1.txt output2.txt