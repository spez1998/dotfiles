#!/bin/bash

if ! type bspc &> /dev/null; then
	echo "bspc not found"
	exit 1
fi

while read -r line; do 
	case $line in
		W*)
			IFS=':'
			set -- ${line#?}
			while [ $# -gt 0 ]; do
				item="$1"
				name="${item#?}"
				case $item in
					f*)
						# free desktop
						echo -n " %{A:bspc desktop -f $name:}"
						echo -n "${name,,}"
						echo -n "%{A} "
						;;
					o*)
						# occupied desktop
						echo -n " %{A:bspc desktop -f $name:}"
						echo -n "$name"
						echo -n "%{A} " 
						;;
					u*)
						# urgent desktop
						echo -n " %{A:bspc desktop -f $name:}"
						echo -n "$name"
						echo -n "%{A} "
						;;
				esac
				shift
			done
	esac
	echo -e -n "\ue0b0"
	echo
done < <(bspc subscribe report)
