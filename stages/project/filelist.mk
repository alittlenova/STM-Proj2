###################################################
# LIBRARY SOURCES
###################################################

# Set mylib folder path.
# IMPORTANT NOTE: change MYLIBTEMPLATE_PATH to your Driver name e.g. JOYSTICK_MYLIBPATH
# e.g. MYLIBPATH=$(SOURCELIB_ROOT)/../mylib
MYLIB_PATH=$(SOURCELIB_ROOT)/../mylib

# Set folder path with header files to include.
CFLAGS += -I$(MYLIB_PATH)

# Including memory heap model
LIBSRCS += $(FREERTOS_PATH)/portable/MemMang/heap_1.c

# List all c files locations that must be included (use space as separate e.g. LIBSRCS += path_to/file1.c path_to/file2.c)
LIBSRCS += $(MYLIB_PATH)/s4459843_reg_oled.c 
LIBSRCS += $(MYLIB_PATH)/s4459843_reg_joystick.c 
LIBSRCS += $(MYLIB_PATH)/s4459843_reg_iss.c
LIBSRCS += $(MYLIB_PATH)/s4459843_reg_lta1000g.c
LIBSRCS += $(MYLIB_PATH)/s4459843_reg_keypad.c
#LIBSRCS += $(MYLIB_PATH)/s4459843_lib_hamming.c
#LIBSRCS += $(MYLIB_PATH)/s4459843_tsk_oled.c
LIBSRCS += $(MYLIB_PATH)/s4459843_tsk_joystick.c
LIBSRCS += $(MYLIB_PATH)/s4459843_CAG_simulator.c
LIBSRCS += $(MYLIB_PATH)/s4459843_CAG_display.c
LIBSRCS += $(MYLIB_PATH)/s4459843_CAG_keypad_grid.c
LIBSRCS += $(MYLIB_PATH)/s4459843_CAG_keypad_mnemonic.c
LIBSRCS += $(MYLIB_PATH)/s4459843_CAG_keypad.c
