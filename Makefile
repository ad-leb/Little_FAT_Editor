.SUFFIXES:
.PHONY: all    zen down clean    edit run    test
.DEFAULT: all



SRCDIR::= src
OBJDIR::= obj
BINDIR::= bin

RAWDIR::= $(OBJDIR)/raw
_BODYDIR::= $(SRCDIR)/_body
IMAGEDIR::= $(SRCDIR)/image
FAT12DIR::= $(SRCDIR)/fat
ROOTFDIR::= $(SRCDIR)/rootf
HELPRDIR::= $(SRCDIR)/helpr
_BOOTDIR::= $(_BODYDIR)/_boot

VPATH= $(SRCDIR):$(_BOOTDIR):$(_BODYDIR):$(IMAGEDIR):$(FAT12DIR):$(ROOTFDIR):$(HELPRDIR):$(RAWDIR):$(OBJDIR):$(BINDIR)




TGT::= prog
_BOOT::= _boot.o
_BODY::= _body.o
IMAGE::= image.o
FAT12::= fat12.o
ROOTF::= rootf.o
HELPR::= helpr.o





_BODY_RAW::= $(shell find $(_BODYDIR) -maxdepth 1 -type f | grep .*.[cs]$$ | sed -e 's/.*\///' -e 's/\..*/.o/')
_BOOT_RAW::= $(shell find $(SRCDIR) -name _boot___* | sed -e 's/.*\///' -e 's/\..*/.o/')
IMAGE_RAW::= $(shell find $(SRCDIR) -name image___* | sed -e 's/.*\///' -e 's/\..*/.o/')
FAT12_RAW::= $(shell find $(SRCDIR) -name fat12___* | sed -e 's/.*\///' -e 's/\..*/.o/')
ROOTF_RAW::= $(shell find $(SRCDIR) -name rootf___* | sed -e 's/.*\///' -e 's/\..*/.o/')
HELPR_RAW::= $(shell find $(SRCDIR) -name helpr___* | sed -e 's/.*\///' -e 's/\..*/.o/')











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
	@for f in *; do if [ ! -d $$f ] && [ ! $$f = 'Makefile' ] && [ ! $$f = 'README.md' ]; then rm -f $$f; fi; done

edit:
	@vim -p $(SRCDIR)/*
run:
	@./$(BINDIR)/$(TGT)


test: init $(FAT12) $(ROOTF) $(HELPR) $(IMAGE) $(_BODY) $(_BOOT)

















$(_BOOT): $(_BOOT_RAW)
	ld -r $(addprefix $(RAWDIR)/, $(_BOOT_RAW)) -o $(OBJDIR)/$@
$(_BODY): $(_BODY_RAW)
	ld -r $(addprefix $(RAWDIR)/, $(_BODY_RAW)) -o $(OBJDIR)/$@
$(IMAGE): $(IMAGE_RAW)
	ld -r $(addprefix $(RAWDIR)/, $(IMAGE_RAW)) -o $(OBJDIR)/$@
$(FAT12): $(FAT12_RAW)
	ld -r $(addprefix $(RAWDIR)/, $(FAT12_RAW)) -o $(OBJDIR)/$@
$(ROOTF): $(ROOTF_RAW)
	ld -r $(addprefix $(RAWDIR)/, $(ROOTF_RAW)) -o $(OBJDIR)/$@
$(HELPR): $(HELPR_RAW)
	ld -r $(addprefix $(RAWDIR)/, $(HELPR_RAW)) -o $(OBJDIR)/$@





%.o: %.c
	gcc -c -fpack-struct -isystem $(_BODYDIR) $< -o $(RAWDIR)/$@
%.o: %.s
	as $< -o $(RAWDIR)/$@
