#
# Include file for OASIS3 Makefile for a Linux system using 
# Portland Group Fortran Compiler and MPICH
#
###############################################################################
#
# CHAN	: communication technique used in OASIS3 (MPI1/MPI2)
CHAN            = MPI1
#
# Paths for libraries, object files and binaries
#
# COUPLE	: path for oasis3-mct main directory
COUPLE          = $(BUILDROOT)/../..
#
# ARCHDIR       : directory created when compiling
ARCHDIR         = $(COUPLE)/build
#
# NETCDF library
NETCDF_INCLUDE  = /apps/netcdf/4.8.0p/include
NETCDF_LIBRARY  = -L/apps/netcdf/4.8.0p/lib -lnetcdff -L/apps/netcdf/4.8.0p/lib -lnetcdf
#
# Compiling and other commands
MAKE        = gmake
F90         = mpif90
F           = $(F90)
f90         = $(F90)
f           = $(F90)
CC          = mpicc
LD          = mpif90
AR          = ar
ARFLAGS     = -ruv
#
# CPP keys and compiler options
# 
CPPDEF    = -Duse_netCDF -Duse_comm_$(CHAN) -D__VERBOSE -DTREAT_OVERLAY
#
# 
F90FLAGS_1 = -g -traceback -fno-alias -ip -align -xHost -O2
f90FLAGS_1  = $(F90FLAGS_1)
FFLAGS_1    = $(F90FLAGS_1)
fFLAGS_1    = $(F90FLAGS_1)
CCFLAGS_1   = 
LDFLAGS     = 
#
###################
#
# Additional definitions that should not be changed
#
FLIBS		= $(NETCDF_LIBRARY)
# BINDIR        : directory for executables
BINDIR          = $(ARCHDIR)/bin
# LIBBUILD      : contains a directory for each library
LIBBUILD        = $(ARCHDIR)/build/lib
# INCPSMILE     : includes all *o and *mod for each library
INCPSMILE       = -I$(LIBBUILD)/psmile.$(CHAN) -I$(LIBBUILD)/pio  -I$(LIBBUILD)/mct -I$(LIBBUILD)/scrip

F90FLAGS  = $(F90FLAGS_1) $(INCPSMILE) $(CPPDEF) -I$(NETCDF_INCLUDE)
f90FLAGS  = $(f90FLAGS_1) $(INCPSMILE) $(CPPDEF) -I$(NETCDF_INCLUDE)
FFLAGS    = $(FFLAGS_1) $(INCPSMILE) $(CPPDEF) -I$(NETCDF_INCLUDE)
fFLAGS    = $(fFLAGS_1) $(INCPSMILE) $(CPPDEF) -I$(NETCDF_INCLUDE)
CCFLAGS   = $(CCFLAGS_1) $(INCPSMILE) $(CPPDEF) -I$(NETCDF_INCLUDE)
#
#############################################################################
