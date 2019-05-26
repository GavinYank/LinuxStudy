
TOP = .

SUB_DIRS += ap
SUB_DIRS += common
SUB_DIRS += gof23pattern
SUB_DIRS += linux_study

ifeq ($(MAKECMDGOALS), all)
LINK_CMD = link
endif

first: linux_study
	@$(MAKE) -s link

include $(TOP)/compile/common.mf

