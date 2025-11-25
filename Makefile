# Brandon Evans
# 11/24/25

# Top-level Makefile

# The subdirs we need
SUBDIRS = librbody

EIGEN_DIR = ../eigen-5.0.0/Eigen

INCLUDES = -I$(EIGEN_DIR)

.PHONY: all $(SUBDIRS) clean

# Default target
all: $(SUBDIRS)

# Build the sub dir
$(SUBDIRS):
	$(MAKE) -C $@

# Clean all subdirs
clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done