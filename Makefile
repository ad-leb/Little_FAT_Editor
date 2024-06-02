.SUFFIXES:
.PHONY: all install    zen down clean    test_build tpush tpull dpush dpull
.DEFAULT: all



PREFIX::=/usr/local


SRCDIR::= src
OBJDIR::= obj
BINDIR::= bin

RAWDIR::= $(OBJDIR)/raw
_BODYDIR::= $(SRCDIR)/_body
INTERDIR::= $(SRCDIR)/inter
IMAGEDIR::= $(SRCDIR)/image
FAT12DIR::= $(SRCDIR)/fat
ROOTFDIR::= $(SRCDIR)/rootf
HELPRDIR::= $(SRCDIR)/helpr
_BOOTDIR::= $(_BODYDIR)/_boot
_HEADDIR::= $(_BODYDIR)/_head

VPATH= $(SRCDIR):$(_BOOTDIR):$(_BODYDIR):$(IMAGEDIR):$(INTERDIR):$(FAT12DIR):$(ROOTFDIR):$(HELPRDIR):$(RAWDIR):$(OBJDIR):$(BINDIR)




TGT::= lfe
DBG::= debug
_BOOT::= _boot.o
_BODY::= _body.o
INTER::= inter.o
IMAGE::= image.o
FAT12::= fat12.o
ROOTF::= rootf.o
HELPR::= helpr.o

ALL_MODULES::= $(_BOOT) $(_BODY) $(INTER) $(HELPR) $(IMAGE) $(FAT12) $(ROOTF)





_BODY_RAW::= $(shell find $(_BODYDIR) -maxdepth 1 -type f | grep .*.[cs]$$ | sed -e 's/.*\///' -e 's/\..*/.o/')
_BOOT_RAW::= $(shell find $(SRCDIR) -name _boot___* | sed -e 's/.*\///' -e 's/\..*/.o/')
INTER_RAW::= $(shell find $(SRCDIR) -name inter___* | sed -e 's/.*\///' -e 's/\..*/.o/')
IMAGE_RAW::= $(shell find $(SRCDIR) -name image___* | sed -e 's/.*\///' -e 's/\..*/.o/')
FAT12_RAW::= $(shell find $(SRCDIR) -name fat12___* | sed -e 's/.*\///' -e 's/\..*/.o/')
ROOTF_RAW::= $(shell find $(SRCDIR) -name rootf___* | sed -e 's/.*\///' -e 's/\..*/.o/')
HELPR_RAW::= $(shell find $(SRCDIR) -name helpr___* | sed -e 's/.*\///' -e 's/\..*/.o/')






TEST_IMG::= floppy.img
TEST_FILES::= obj
TEST_MODULES::= $(_BOOT) $(_BODY) $(INTER) $(HELPR) $(IMAGE) $(FAT12) $(ROOTF)










all: init $(ALL_MODULES)
	ld -e _boot -lc --dynamic-linker=/lib64/ld-linux-x86-64.so.2 -o $(BINDIR)/$(TGT) $(addprefix $(OBJDIR)/, $(ALL_MODULES))
install: all
	mkdir -p bin
	install $(BINDIR)/$(TGT) $(PREFIX)/bin
init:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(RAWDIR)
	@mkdir -p $(BINDIR)


zen: down clean
	@rm -rf $(OBJDIR) 
	@rm -rf $(BINDIR)
down:
	@rm -fd $(RAWDIR)/*
	@rm -fd $(OBJDIR)/*
	@rm -fd $(BINDIR)/*
clean:
	@for f in *; do if [ ! $$f = $(SRCDIR) ] && [ ! $$f = $(OBJDIR) ] && [ ! $$f = $(BINDIR) ] && [ ! $$f = 'Makefile' ] && [ ! $$f = 'README.md' ]; then rm -fr $$f; fi; done





test_build: init $(TEST_MODULES)
	ld -e _boot -lc --dynamic-linker=/lib64/ld-linux-x86-64.so.2 -o $(BINDIR)/$(DBG) $(addprefix $(OBJDIR)/, $(TEST_MODULES))

tpush: test_build 
	$(BINDIR)/$(DBG) push $(TEST_IMG) -c $(TEST_FILES)
tpull: test_build 
	$(BINDIR)/$(DBG) pull $(TEST_IMG) all
tlist: test_build 
	$(BINDIR)/$(DBG) list $(TEST_IMG) content
tlistt: test_build 
	$(BINDIR)/$(DBG) list $(TEST_IMG) title
tborn: test_build
	$(BINDIR)/$(DBG) born $(TEST_IMG) sn=185147902 oem=LFE\ TEST fs=FAT12 vl=ITSPOPS 

dpush: test_build
	gdb --args $(BINDIR)/$(DBG) push $(TEST_IMG) -c $(TEST_FILES)
dpull: test_build
	gdb --args $(BINDIR)/$(DBG) pull $(TEST_IMG) all
dlist: test_build
	gdb --args $(BINDIR)/$(DBG) list $(TEST_IMG) content
dlistt: test_build
	gdb --args $(BINDIR)/$(DBG) list $(TEST_IMG) title
dborn: test_build
	gdb --args $(BINDIR)/$(DBG) born $(TEST_IMG) -c sn=10334718 vl=ITSPOPS

















$(_BOOT): $(_BOOT_RAW)
	ld -r $(addprefix $(RAWDIR)/, $(_BOOT_RAW)) -o $(OBJDIR)/$@
$(_BODY): $(_BODY_RAW)
	ld -r $(addprefix $(RAWDIR)/, $(_BODY_RAW)) -o $(OBJDIR)/$@
$(INTER): $(INTER_RAW)
	ld -r $(addprefix $(RAWDIR)/, $(INTER_RAW)) -o $(OBJDIR)/$@
$(IMAGE): $(IMAGE_RAW)
	ld -r $(addprefix $(RAWDIR)/, $(IMAGE_RAW)) -o $(OBJDIR)/$@
$(FAT12): $(FAT12_RAW)
	ld -r $(addprefix $(RAWDIR)/, $(FAT12_RAW)) -o $(OBJDIR)/$@
$(ROOTF): $(ROOTF_RAW)
	ld -r $(addprefix $(RAWDIR)/, $(ROOTF_RAW)) -o $(OBJDIR)/$@
$(HELPR): $(HELPR_RAW)
	ld -r $(addprefix $(RAWDIR)/, $(HELPR_RAW)) -o $(OBJDIR)/$@





$(TEST_IMG): tborn
%.o: %.c
	gcc -c -fpack-struct -isystem $(_HEADDIR) $< -o $(RAWDIR)/$@
%.o: %.s
	as $< -o $(RAWDIR)/$@
