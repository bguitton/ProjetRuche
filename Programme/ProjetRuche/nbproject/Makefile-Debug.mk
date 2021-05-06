#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=xtensa-esp32-elf-gcc
CCC=xtensa-esp32-elf-g++
CXX=xtensa-esp32-elf-g++
FC=gfortran
AS=xtensa-esp32-elf-as

# Macros
CND_PLATFORM=esp32-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/b9dd8f7c/Balance.o \
	${OBJECTDIR}/_ext/329de6a5/ControleurRuche.o \
	${OBJECTDIR}/_ext/cab35baa/Environnement.o \
	${OBJECTDIR}/Menu.o \
	${OBJECTDIR}/main.ino.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projetruche

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projetruche: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projetruche ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/b9dd8f7c/Balance.o: /home/USERS/ELEVES/SNIR2019/bguitton/Bureau/ProjetRuche/Programme/ClasseBalance/Balance.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/b9dd8f7c
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/b9dd8f7c/Balance.o /home/USERS/ELEVES/SNIR2019/bguitton/Bureau/ProjetRuche/Programme/ClasseBalance/Balance.cpp

${OBJECTDIR}/_ext/329de6a5/ControleurRuche.o: /home/USERS/ELEVES/SNIR2019/bguitton/Bureau/ProjetRuche/Programme/ClasseControleur/ControleurRuche.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/329de6a5
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/329de6a5/ControleurRuche.o /home/USERS/ELEVES/SNIR2019/bguitton/Bureau/ProjetRuche/Programme/ClasseControleur/ControleurRuche.cpp

${OBJECTDIR}/_ext/cab35baa/Environnement.o: /home/USERS/ELEVES/SNIR2019/bguitton/Bureau/ProjetRuche/Programme/ClasseEnvironnement/Environnement.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/cab35baa
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/cab35baa/Environnement.o /home/USERS/ELEVES/SNIR2019/bguitton/Bureau/ProjetRuche/Programme/ClasseEnvironnement/Environnement.cpp

${OBJECTDIR}/Menu.o: Menu.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Menu.o Menu.cpp

${OBJECTDIR}/main.ino.o: main.ino.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.ino.o main.ino.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
