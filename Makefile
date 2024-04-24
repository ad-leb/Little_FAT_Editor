.SUFFIXES:
.PHONY: all    zen down clean    edit run
.DEFAULT: all



SRCDIR::= src
OBJDIR::= obj
BINDIR::= bin

RAWDIR::= $(OBJDIR)/raw
IMAGEDIR::= $(SRCDIR)/image
FAT12DIR::= $(IMAGEDIR)/fat
ROOTFDIR::= $(IMAGEDIR)/rootf

VPATH= $(SRCDIR):$(FAT12DIR):$(ROOTFDIR):$(RAWDIR):$(OBJDIR):$(BINDIR)




TGT::= prog
FAT12::= fat12.o
ROOTF::= rootf.o





FAT12_RAW::= $(shell find $(SRCDIR) -name fat12___* | sed -e 's/.*\///' -e 's/\..*/.o/')
ROOTF_RAW::= $(shell find $(SRCDIR) -name rootf___* | sed -e 's/.*\///' -e 's/\..*/.o/')











all: zen init $(TGT)
init:
	@[ ! -e $(OBJDIR) ] && mkdir $(OBJDIR) || true
	@[ ! -e $(RAWDIR) ] && mkdir $(RAWDIR) || true
	@[ ! -e $(BINDIR) ] && mkdir $(BINDIR) || true

zen: clean down
	@rm -rf $(OBJDIR) 
	@rm -rf $(BINDIR)
down:
	@rm -fd $(RAWDIR)/*
	@rm -fd $(OBJDIR)/*
	@rm -fd $(BINDIR)/*
clean:
	@for f in *; do if [ ! -d $$f ] && [ ! $$f = 'Makefile' ] && [ ! $$f = 'README' ]; then rm -f $$f; fi; done

edit:
	@vim -p $(SRCDIR)/*
run:
	@./$(BINDIR)/$(TGT)


test: init $(FAT12) $(ROOTF)

















$(FAT12): $(FAT12_RAW)
	ld -r $(addprefix $(RAWDIR)/, $(FAT12_RAW)) -o $(OBJDIR)/$@
$(ROOTF): $(ROOTF_RAW)
	ld -r $(addprefix $(RAWDIR)/, $(ROOTF_RAW)) -o $(OBJDIR)/$@





%.o: %.c
	gcc -c $< -o $(RAWDIR)/$@
%.o: %.s
	as $< -o $(RAWDIR)/$@
