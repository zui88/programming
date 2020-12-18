#!/bin/bash


# ================ Aufrufsyntax ================

# tree [-d] [-r "pattern"] [directory]

# Ausgabe:

# dateiname*    einfache Datei und ausfuehrbar
# dateiname/    Directory
# dateiname/-   leeres Directory
# dateiname/-r  nicht lesbares Directory (Inhalt nicht auflistbar)
# dateiname/-x  nicht ausfuehrbares Directory (kein cd moeglich)


# ================ functions ================


# usage - gibt die Hilfe mit der korrekten Aufrufsyntax aus
usage() {
    # im Fehlerfall in die Standartfehlerausgabe umleiten
    echo "$0 [-d] [-r \"pattern\"] [directory]" >&2
    echo "     -d nur Verzeichnisse auflisten"  >&2
    echo "     -r nur Verzeichnisse und Dateien, die durch pattern abgedeckt sind" >&2
}

# akutelle Verzeichnis als Parameter uebergeben
function baum {
    # wenn nicht ausfuehrbahres Verzeichnis -> schreibgeschuetzt?
    # "...", da falls Leerzeichen vorhanden
    if [ ! -x "$1" ]; then echo -e "-x\c"; exit; fi

    # sonst, in aktuellen Ordner wechseln
    cd $1

    # -f  Disable file name generation (globbing). -> ???
    set -f
    # in der "then-Bedingung" -> nicht lesbares Directory -> exit program
    # warum in geschweiften Klammern?
    # (...) -> open subshell
    # {...} -> with side-effects -> for: XXX-r 
    # append "-r" at the end of the line and exit
    set "" $(ls -A 2>/dev/null) || { echo -e "-r\c"; exit; }
    shift
    # $# -> number of arguments
    if [ $# -eq 0 ]; then echo -e "-\c"; exit; fi

    # pos. Param. als __ein__ zusammenhaengender String
        # result of $(ls -A)
    args="$*"
    temp_args=""


    # $args werden gefiltert
    # $option kein leerer String
    if [ ! -z "$option" ]
    then
	# Filterung -> nur Directories in args
	# *d*   -> regex
	case $option in
	    *d*) for i in $args
		 do
		     [ -d "$i" ] && temp_args="$temp_args $i"
		 done
		 args="$temp_args"
		 temp_args="";;
	esac

	case $option in
	    *r*) for i in $args
		 do
		     if [ -d "$i" ] || case $i in
			    $ra) true;;
			    *) false;;
			esac
		     then
			 temp_args="$temp_args $i"
		     fi
		 done
		 args="$temp_args"
		 temp_args=""
	esac
    fi


    if [ ! -z "$args" ]
    then
	set "" $(ls -AdF $args 2>/dev/null)
    else
	set ""
    fi

    shift

    while [ ! -z "$2" ]
    do
	echo -e "\n${tiefe}|-- $1\c"
	if [ -d "$1" ]; then (tiefe="${tiefe}|    "; baum $1); fi

	# Achtung: die () sind sehr wichtig
	# Nur in der Subshell darf die Variable $tiefe
	# verlaengert werden.

	shift
    done

    # letzter Teil eines Teilbaumes
    if [ ! -z "$1" ]
    then
	echo -e "\n${tiefe}\`-- $1\c"
	if [ -d "$1" ]; then (tiefe="${tiefe}    "; baum $1) fi
    fi
}


# ================ main ================


# Abarbeiten der angegebenen Optionen
# Betrachte Optionen [hH]->regex, ?, r mit Pattern dahinter (deswegen ":") und d
while getopts hH\?r:d opt
do
    case $opt in
	# Vom Benutzer gesetzte Optionen merken
	d) option="${option}d";;
	r) option="${option}r";ra="$OPTARG";;

	# Hilfe ausgeben und Beenden
	\?) usage; exit 1;;
	[hH]) usage; exit 1;;
    esac
done

# Optionen sind in ${optionen} gemerkt!!!

# letzte Position nach $1 -> aktuelles Verzeichnis
# tree.sh [-dr] <Verzeichnis>
# OPTIND := index der Option
# every option string has an index identifying the position
shift $(expr $OPTIND - 1) 
dir=${1:-$(pwd)}

# Pruefen des aktuellen Verzeichnisses
if [ ! -d "$dir" ]
then
    echo "$0: $dir ist kein Directory" >&2
    usage
    exit 1
fi


# Wurzel anzeigen
echo -e "$dir\c"
# Baum durchlaufen (mit allen Teilbaeumen, rekursiv)
baum $dir
