echo Enter a number n
read n
f=1
i=1
while [ $i -le $n ]
do
	f=`expr $i \* $f`
	i=`expr $i + 1`
done
echo The factorial of $n is $f

