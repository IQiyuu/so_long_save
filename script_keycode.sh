array=( `cat keycodes | tr -d '=\n0123456789' | sed "s/ .$//"` )
array2=( `cat keycodes | tr -d '=\n[^A-Z-a-z.?]'` )


echo "start"
if [ $1 == "list" ]
then
	found=1
	for k in "${array[@]}"
	do
		echo "- $k"
	done
else
	for k in "${!array[@]}"
	do
		if [ ${array[$k]} == $1 ]
		then 
			echo "le keycode de $1 est ${array2[$k]}"
			found=1
		fi
	done
fi
if [ -e $found ]
then
	echo "$1 not found"
fi
echo "end"