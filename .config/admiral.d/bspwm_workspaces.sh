#!/bin/bash

if ! type bspc &> /dev/null; then
	echo "bspc not found"
	exit 1
fi

while read -r line; do 
	echo -n "%{B#928374}%{F#32302f}"
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
	echo -n -e "%{F#928374}%{B-}\ue0b0%{F-}"
	echo
done < <(bspc subscribe report)
