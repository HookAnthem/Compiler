#!/bin/bash
for i in examples/simple_expressions/*.cpsl
do
./cpslCompiler <$i> $i.asm
java -jar Mars4_5.jar $i.asm
done
for i in examples/udt/*.cpsl
do
./cpslCompiler <$i> $i.asm
java -jar Mars4_5.jar $i.asm
done
for i in examples./control/*.cpsl
do
./cpslCompiler <$i> $i.asm
java -jar Mars4_5.jar $i.asm
done
for i in examples/fu./ction/*.cpsl
do
./cpslCompiler <$i> $i.asm
java -jar Mars4_5.jar $i.asm
done

