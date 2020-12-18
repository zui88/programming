.PHONY: all

args := --filter C:\Users\mburkhardt\.bin\pandoc-crossref \
	--filter pandoc-citeproc \
	--bibliography=citations.bib

md := $(wildcard *.md)
pdf := $(patsubst %.md,%.pdf,$(md))

all: $(pdf)

%.pdf: %.md
	pandoc.exe $< -o $@
