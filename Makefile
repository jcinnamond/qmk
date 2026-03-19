kb = splitkb/halcyon/kyria/rev4
km = jc
userspace=userspace
kmdir = $(userspace)/keyboards/splitkb/halcyon/kyria/keymaps/$(km)

qmk = qmk

$(userspace)/kyria-$(km): $(kmdir)/keymap.c $(kmdir)/rules.mk
	$(qmk) compile -kb $(kb) -km $(km) -e HLC_TFT_DISPLAY=1 -e TARGET=kyria-$(km)

flash: $(userspace)/kyria-jc.uf2
	$(qmk) flash $<
