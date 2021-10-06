.PHONY: html
html: $(patsubst %.md, %.html, $(wildcard *.md))

%.html: %.md
	markdown2 \
	  --extras=code-friendly \
	  --extras=fenced-code-blocks \
	  --extras=tables \
	  $< > $@

.PHONY: clean
clean:
	$(RM) *.html
