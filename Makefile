UNAME := $(shell uname)

all: parser

lexer: lexer_standalone.l
	flex lexer_standalone.l
	gcc -o lexer_standalone lex.yy.c
	./lexer_standalone testProg.cmm


parser.tab.c parser.tab.h:	parser.y
	bison -t -v -d --graph -x parser.y
	bison --print-datadir
	xsltproc /usr/local/share/bison/xslt/xml2xhtml.xsl parser.xml >parser.html

lex.yy.c: lexer.l parser.tab.h
	flex lexer.l

parser: lex.yy.c parser.tab.c parser.tab.h symbolTable.h AST.h
	@if [ $(UNAME) = Linux ]; then\
        gcc -o parser parser.tab.c lex.yy.c -w;\
    fi
	@if [ $(UNAME) = Darwin ]; then\
		{ time -p gcc -o parser parser.tab.c lex.yy.c -w; } 2> time.txt;\
    fi
	@if [ $(UNAME) = Solaris ]; then\
        timecmd gcc -o parser parser.tab.c lex.yy.c -w > time.txt;\
    fi
	
	./parser testProg.cmm 

clean:
	rm -f parser lexer parser.tab.c lex.yy.c parser.tab.h parser.output
	rm -f parser lexer parser.gv parser.html parser.ps parser.xml lexer_standalone
	ls -l