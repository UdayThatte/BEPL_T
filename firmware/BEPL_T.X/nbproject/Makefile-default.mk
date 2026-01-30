#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/BEPL_T.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/BEPL_T.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/API/Amplifier_Com.c ../src/API/CAN_Enco_Com.c ../src/API/Global_Vars.c ../src/API/Protocol.c ../src/API/Ampli_functions.c ../src/API/AtmelFlashMem.c ../src/API/BoardTemp.c ../src/API/RTC.c ../src/API/KBD_5X8.c ../src/API/LCD_functions.c ../src/BSP/CAN_Comm.c ../src/BSP/Events.c ../src/BSP/ETH_Module_Com.c ../src/BSP/SSI_Enco.c ../src/BSP/Beeps.c ../src/BSP/DataFlash_Comm.c ../src/BSP/I2C_comm.c ../src/BSP/RTC_Comm.c ../src/BSP/KBD_5X8_rd.c ../src/BSP/LCD_Comm.c ../src/config/default/peripheral/can/plib_can1.c ../src/config/default/peripheral/clk/plib_clk.c ../src/config/default/peripheral/coretimer/plib_coretimer.c ../src/config/default/peripheral/evic/plib_evic.c ../src/config/default/peripheral/gpio/plib_gpio.c ../src/config/default/peripheral/i2c/master/plib_i2c2_master.c ../src/config/default/peripheral/spi/spi_master/plib_spi1_master.c ../src/config/default/peripheral/uart/plib_uart3.c ../src/config/default/peripheral/uart/plib_uart1.c ../src/config/default/peripheral/uart/plib_uart5.c ../src/config/default/stdio/xc32_monitor.c ../src/config/default/initialization.c ../src/config/default/interrupts.c ../src/config/default/exceptions.c ../src/Utils/BCD_Utils.c ../src/Utils/Utils.c ../src/main.c ../src/App_Protocol.c ../src/config/default/peripheral/adc/plib_adc.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/659819008/Amplifier_Com.o ${OBJECTDIR}/_ext/659819008/CAN_Enco_Com.o ${OBJECTDIR}/_ext/659819008/Global_Vars.o ${OBJECTDIR}/_ext/659819008/Protocol.o ${OBJECTDIR}/_ext/659819008/Ampli_functions.o ${OBJECTDIR}/_ext/659819008/AtmelFlashMem.o ${OBJECTDIR}/_ext/659819008/BoardTemp.o ${OBJECTDIR}/_ext/659819008/RTC.o ${OBJECTDIR}/_ext/659819008/KBD_5X8.o ${OBJECTDIR}/_ext/659819008/LCD_functions.o ${OBJECTDIR}/_ext/659820069/CAN_Comm.o ${OBJECTDIR}/_ext/659820069/Events.o ${OBJECTDIR}/_ext/659820069/ETH_Module_Com.o ${OBJECTDIR}/_ext/659820069/SSI_Enco.o ${OBJECTDIR}/_ext/659820069/Beeps.o ${OBJECTDIR}/_ext/659820069/DataFlash_Comm.o ${OBJECTDIR}/_ext/659820069/I2C_comm.o ${OBJECTDIR}/_ext/659820069/RTC_Comm.o ${OBJECTDIR}/_ext/659820069/KBD_5X8_rd.o ${OBJECTDIR}/_ext/659820069/LCD_Comm.o ${OBJECTDIR}/_ext/60165182/plib_can1.o ${OBJECTDIR}/_ext/60165520/plib_clk.o ${OBJECTDIR}/_ext/1249264884/plib_coretimer.o ${OBJECTDIR}/_ext/1865200349/plib_evic.o ${OBJECTDIR}/_ext/1865254177/plib_gpio.o ${OBJECTDIR}/_ext/513455433/plib_i2c2_master.o ${OBJECTDIR}/_ext/298189674/plib_spi1_master.o ${OBJECTDIR}/_ext/1865657120/plib_uart3.o ${OBJECTDIR}/_ext/1865657120/plib_uart1.o ${OBJECTDIR}/_ext/1865657120/plib_uart5.o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ${OBJECTDIR}/_ext/1171490990/initialization.o ${OBJECTDIR}/_ext/1171490990/interrupts.o ${OBJECTDIR}/_ext/1171490990/exceptions.o ${OBJECTDIR}/_ext/1549516009/BCD_Utils.o ${OBJECTDIR}/_ext/1549516009/Utils.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/App_Protocol.o ${OBJECTDIR}/_ext/60163342/plib_adc.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/659819008/Amplifier_Com.o.d ${OBJECTDIR}/_ext/659819008/CAN_Enco_Com.o.d ${OBJECTDIR}/_ext/659819008/Global_Vars.o.d ${OBJECTDIR}/_ext/659819008/Protocol.o.d ${OBJECTDIR}/_ext/659819008/Ampli_functions.o.d ${OBJECTDIR}/_ext/659819008/AtmelFlashMem.o.d ${OBJECTDIR}/_ext/659819008/BoardTemp.o.d ${OBJECTDIR}/_ext/659819008/RTC.o.d ${OBJECTDIR}/_ext/659819008/KBD_5X8.o.d ${OBJECTDIR}/_ext/659819008/LCD_functions.o.d ${OBJECTDIR}/_ext/659820069/CAN_Comm.o.d ${OBJECTDIR}/_ext/659820069/Events.o.d ${OBJECTDIR}/_ext/659820069/ETH_Module_Com.o.d ${OBJECTDIR}/_ext/659820069/SSI_Enco.o.d ${OBJECTDIR}/_ext/659820069/Beeps.o.d ${OBJECTDIR}/_ext/659820069/DataFlash_Comm.o.d ${OBJECTDIR}/_ext/659820069/I2C_comm.o.d ${OBJECTDIR}/_ext/659820069/RTC_Comm.o.d ${OBJECTDIR}/_ext/659820069/KBD_5X8_rd.o.d ${OBJECTDIR}/_ext/659820069/LCD_Comm.o.d ${OBJECTDIR}/_ext/60165182/plib_can1.o.d ${OBJECTDIR}/_ext/60165520/plib_clk.o.d ${OBJECTDIR}/_ext/1249264884/plib_coretimer.o.d ${OBJECTDIR}/_ext/1865200349/plib_evic.o.d ${OBJECTDIR}/_ext/1865254177/plib_gpio.o.d ${OBJECTDIR}/_ext/513455433/plib_i2c2_master.o.d ${OBJECTDIR}/_ext/298189674/plib_spi1_master.o.d ${OBJECTDIR}/_ext/1865657120/plib_uart3.o.d ${OBJECTDIR}/_ext/1865657120/plib_uart1.o.d ${OBJECTDIR}/_ext/1865657120/plib_uart5.o.d ${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d ${OBJECTDIR}/_ext/1171490990/initialization.o.d ${OBJECTDIR}/_ext/1171490990/interrupts.o.d ${OBJECTDIR}/_ext/1171490990/exceptions.o.d ${OBJECTDIR}/_ext/1549516009/BCD_Utils.o.d ${OBJECTDIR}/_ext/1549516009/Utils.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/1360937237/App_Protocol.o.d ${OBJECTDIR}/_ext/60163342/plib_adc.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/659819008/Amplifier_Com.o ${OBJECTDIR}/_ext/659819008/CAN_Enco_Com.o ${OBJECTDIR}/_ext/659819008/Global_Vars.o ${OBJECTDIR}/_ext/659819008/Protocol.o ${OBJECTDIR}/_ext/659819008/Ampli_functions.o ${OBJECTDIR}/_ext/659819008/AtmelFlashMem.o ${OBJECTDIR}/_ext/659819008/BoardTemp.o ${OBJECTDIR}/_ext/659819008/RTC.o ${OBJECTDIR}/_ext/659819008/KBD_5X8.o ${OBJECTDIR}/_ext/659819008/LCD_functions.o ${OBJECTDIR}/_ext/659820069/CAN_Comm.o ${OBJECTDIR}/_ext/659820069/Events.o ${OBJECTDIR}/_ext/659820069/ETH_Module_Com.o ${OBJECTDIR}/_ext/659820069/SSI_Enco.o ${OBJECTDIR}/_ext/659820069/Beeps.o ${OBJECTDIR}/_ext/659820069/DataFlash_Comm.o ${OBJECTDIR}/_ext/659820069/I2C_comm.o ${OBJECTDIR}/_ext/659820069/RTC_Comm.o ${OBJECTDIR}/_ext/659820069/KBD_5X8_rd.o ${OBJECTDIR}/_ext/659820069/LCD_Comm.o ${OBJECTDIR}/_ext/60165182/plib_can1.o ${OBJECTDIR}/_ext/60165520/plib_clk.o ${OBJECTDIR}/_ext/1249264884/plib_coretimer.o ${OBJECTDIR}/_ext/1865200349/plib_evic.o ${OBJECTDIR}/_ext/1865254177/plib_gpio.o ${OBJECTDIR}/_ext/513455433/plib_i2c2_master.o ${OBJECTDIR}/_ext/298189674/plib_spi1_master.o ${OBJECTDIR}/_ext/1865657120/plib_uart3.o ${OBJECTDIR}/_ext/1865657120/plib_uart1.o ${OBJECTDIR}/_ext/1865657120/plib_uart5.o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ${OBJECTDIR}/_ext/1171490990/initialization.o ${OBJECTDIR}/_ext/1171490990/interrupts.o ${OBJECTDIR}/_ext/1171490990/exceptions.o ${OBJECTDIR}/_ext/1549516009/BCD_Utils.o ${OBJECTDIR}/_ext/1549516009/Utils.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/App_Protocol.o ${OBJECTDIR}/_ext/60163342/plib_adc.o

# Source Files
SOURCEFILES=../src/API/Amplifier_Com.c ../src/API/CAN_Enco_Com.c ../src/API/Global_Vars.c ../src/API/Protocol.c ../src/API/Ampli_functions.c ../src/API/AtmelFlashMem.c ../src/API/BoardTemp.c ../src/API/RTC.c ../src/API/KBD_5X8.c ../src/API/LCD_functions.c ../src/BSP/CAN_Comm.c ../src/BSP/Events.c ../src/BSP/ETH_Module_Com.c ../src/BSP/SSI_Enco.c ../src/BSP/Beeps.c ../src/BSP/DataFlash_Comm.c ../src/BSP/I2C_comm.c ../src/BSP/RTC_Comm.c ../src/BSP/KBD_5X8_rd.c ../src/BSP/LCD_Comm.c ../src/config/default/peripheral/can/plib_can1.c ../src/config/default/peripheral/clk/plib_clk.c ../src/config/default/peripheral/coretimer/plib_coretimer.c ../src/config/default/peripheral/evic/plib_evic.c ../src/config/default/peripheral/gpio/plib_gpio.c ../src/config/default/peripheral/i2c/master/plib_i2c2_master.c ../src/config/default/peripheral/spi/spi_master/plib_spi1_master.c ../src/config/default/peripheral/uart/plib_uart3.c ../src/config/default/peripheral/uart/plib_uart1.c ../src/config/default/peripheral/uart/plib_uart5.c ../src/config/default/stdio/xc32_monitor.c ../src/config/default/initialization.c ../src/config/default/interrupts.c ../src/config/default/exceptions.c ../src/Utils/BCD_Utils.c ../src/Utils/Utils.c ../src/main.c ../src/App_Protocol.c ../src/config/default/peripheral/adc/plib_adc.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/BEPL_T.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX795F512L
MP_LINKER_FILE_OPTION=,--script="..\src\config\default\p32MX795F512L.ld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/659819008/Amplifier_Com.o: ../src/API/Amplifier_Com.c  .generated_files/flags/default/a1733ef3a8dad65655d0c3574ed9f8f638e7a6a8 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659819008" 
	@${RM} ${OBJECTDIR}/_ext/659819008/Amplifier_Com.o.d 
	@${RM} ${OBJECTDIR}/_ext/659819008/Amplifier_Com.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659819008/Amplifier_Com.o.d" -o ${OBJECTDIR}/_ext/659819008/Amplifier_Com.o ../src/API/Amplifier_Com.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659819008/CAN_Enco_Com.o: ../src/API/CAN_Enco_Com.c  .generated_files/flags/default/d60b02b2762688f51829147a68ba512d2d1925da .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659819008" 
	@${RM} ${OBJECTDIR}/_ext/659819008/CAN_Enco_Com.o.d 
	@${RM} ${OBJECTDIR}/_ext/659819008/CAN_Enco_Com.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659819008/CAN_Enco_Com.o.d" -o ${OBJECTDIR}/_ext/659819008/CAN_Enco_Com.o ../src/API/CAN_Enco_Com.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659819008/Global_Vars.o: ../src/API/Global_Vars.c  .generated_files/flags/default/73a802f68d6e53ecc6b2341cc4f164f863f87745 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659819008" 
	@${RM} ${OBJECTDIR}/_ext/659819008/Global_Vars.o.d 
	@${RM} ${OBJECTDIR}/_ext/659819008/Global_Vars.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659819008/Global_Vars.o.d" -o ${OBJECTDIR}/_ext/659819008/Global_Vars.o ../src/API/Global_Vars.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659819008/Protocol.o: ../src/API/Protocol.c  .generated_files/flags/default/52ee6583e697a6d043940ac7318726bbf244d615 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659819008" 
	@${RM} ${OBJECTDIR}/_ext/659819008/Protocol.o.d 
	@${RM} ${OBJECTDIR}/_ext/659819008/Protocol.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659819008/Protocol.o.d" -o ${OBJECTDIR}/_ext/659819008/Protocol.o ../src/API/Protocol.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659819008/Ampli_functions.o: ../src/API/Ampli_functions.c  .generated_files/flags/default/99ed14956d9c9ee56d28c5f33f816036b4337c8 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659819008" 
	@${RM} ${OBJECTDIR}/_ext/659819008/Ampli_functions.o.d 
	@${RM} ${OBJECTDIR}/_ext/659819008/Ampli_functions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659819008/Ampli_functions.o.d" -o ${OBJECTDIR}/_ext/659819008/Ampli_functions.o ../src/API/Ampli_functions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659819008/AtmelFlashMem.o: ../src/API/AtmelFlashMem.c  .generated_files/flags/default/dcaa169f2321df6084fad80e5dd07c7c3de21dec .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659819008" 
	@${RM} ${OBJECTDIR}/_ext/659819008/AtmelFlashMem.o.d 
	@${RM} ${OBJECTDIR}/_ext/659819008/AtmelFlashMem.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659819008/AtmelFlashMem.o.d" -o ${OBJECTDIR}/_ext/659819008/AtmelFlashMem.o ../src/API/AtmelFlashMem.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659819008/BoardTemp.o: ../src/API/BoardTemp.c  .generated_files/flags/default/37dec3664c259bd898a7991d814d8d33d2e641d7 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659819008" 
	@${RM} ${OBJECTDIR}/_ext/659819008/BoardTemp.o.d 
	@${RM} ${OBJECTDIR}/_ext/659819008/BoardTemp.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659819008/BoardTemp.o.d" -o ${OBJECTDIR}/_ext/659819008/BoardTemp.o ../src/API/BoardTemp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659819008/RTC.o: ../src/API/RTC.c  .generated_files/flags/default/b8fabda72b481d44c4065aef517ee7a3e5bdb6af .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659819008" 
	@${RM} ${OBJECTDIR}/_ext/659819008/RTC.o.d 
	@${RM} ${OBJECTDIR}/_ext/659819008/RTC.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659819008/RTC.o.d" -o ${OBJECTDIR}/_ext/659819008/RTC.o ../src/API/RTC.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659819008/KBD_5X8.o: ../src/API/KBD_5X8.c  .generated_files/flags/default/a159c835cc6a7845fb6562316cc6ff3a4f40f912 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659819008" 
	@${RM} ${OBJECTDIR}/_ext/659819008/KBD_5X8.o.d 
	@${RM} ${OBJECTDIR}/_ext/659819008/KBD_5X8.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659819008/KBD_5X8.o.d" -o ${OBJECTDIR}/_ext/659819008/KBD_5X8.o ../src/API/KBD_5X8.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659819008/LCD_functions.o: ../src/API/LCD_functions.c  .generated_files/flags/default/f3440260491c9232595f4c0c697e706913407337 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659819008" 
	@${RM} ${OBJECTDIR}/_ext/659819008/LCD_functions.o.d 
	@${RM} ${OBJECTDIR}/_ext/659819008/LCD_functions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659819008/LCD_functions.o.d" -o ${OBJECTDIR}/_ext/659819008/LCD_functions.o ../src/API/LCD_functions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659820069/CAN_Comm.o: ../src/BSP/CAN_Comm.c  .generated_files/flags/default/48a45b1218eaf26fe5bc81ecc1bce7c8a08e6c32 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659820069" 
	@${RM} ${OBJECTDIR}/_ext/659820069/CAN_Comm.o.d 
	@${RM} ${OBJECTDIR}/_ext/659820069/CAN_Comm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659820069/CAN_Comm.o.d" -o ${OBJECTDIR}/_ext/659820069/CAN_Comm.o ../src/BSP/CAN_Comm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659820069/Events.o: ../src/BSP/Events.c  .generated_files/flags/default/199a0360271fb0698643f759c9e795c47d5f7dd0 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659820069" 
	@${RM} ${OBJECTDIR}/_ext/659820069/Events.o.d 
	@${RM} ${OBJECTDIR}/_ext/659820069/Events.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659820069/Events.o.d" -o ${OBJECTDIR}/_ext/659820069/Events.o ../src/BSP/Events.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659820069/ETH_Module_Com.o: ../src/BSP/ETH_Module_Com.c  .generated_files/flags/default/5c3dbbf62437134f32bd92f6e42afaef56e23112 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659820069" 
	@${RM} ${OBJECTDIR}/_ext/659820069/ETH_Module_Com.o.d 
	@${RM} ${OBJECTDIR}/_ext/659820069/ETH_Module_Com.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659820069/ETH_Module_Com.o.d" -o ${OBJECTDIR}/_ext/659820069/ETH_Module_Com.o ../src/BSP/ETH_Module_Com.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659820069/SSI_Enco.o: ../src/BSP/SSI_Enco.c  .generated_files/flags/default/8a954b9b696b031d7eff50495fdb005c2a657adb .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659820069" 
	@${RM} ${OBJECTDIR}/_ext/659820069/SSI_Enco.o.d 
	@${RM} ${OBJECTDIR}/_ext/659820069/SSI_Enco.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659820069/SSI_Enco.o.d" -o ${OBJECTDIR}/_ext/659820069/SSI_Enco.o ../src/BSP/SSI_Enco.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659820069/Beeps.o: ../src/BSP/Beeps.c  .generated_files/flags/default/43e8c779267738a96ccc4e16f0e6ac9888b9608b .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659820069" 
	@${RM} ${OBJECTDIR}/_ext/659820069/Beeps.o.d 
	@${RM} ${OBJECTDIR}/_ext/659820069/Beeps.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659820069/Beeps.o.d" -o ${OBJECTDIR}/_ext/659820069/Beeps.o ../src/BSP/Beeps.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659820069/DataFlash_Comm.o: ../src/BSP/DataFlash_Comm.c  .generated_files/flags/default/2e8a013559e200220ed31349dfe53c67b679f880 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659820069" 
	@${RM} ${OBJECTDIR}/_ext/659820069/DataFlash_Comm.o.d 
	@${RM} ${OBJECTDIR}/_ext/659820069/DataFlash_Comm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659820069/DataFlash_Comm.o.d" -o ${OBJECTDIR}/_ext/659820069/DataFlash_Comm.o ../src/BSP/DataFlash_Comm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659820069/I2C_comm.o: ../src/BSP/I2C_comm.c  .generated_files/flags/default/1da7dff7d9843caf9503feb2b8306eba1a2ee38c .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659820069" 
	@${RM} ${OBJECTDIR}/_ext/659820069/I2C_comm.o.d 
	@${RM} ${OBJECTDIR}/_ext/659820069/I2C_comm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659820069/I2C_comm.o.d" -o ${OBJECTDIR}/_ext/659820069/I2C_comm.o ../src/BSP/I2C_comm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659820069/RTC_Comm.o: ../src/BSP/RTC_Comm.c  .generated_files/flags/default/f9f3defd2659555a212e145034307f117c9eb312 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659820069" 
	@${RM} ${OBJECTDIR}/_ext/659820069/RTC_Comm.o.d 
	@${RM} ${OBJECTDIR}/_ext/659820069/RTC_Comm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659820069/RTC_Comm.o.d" -o ${OBJECTDIR}/_ext/659820069/RTC_Comm.o ../src/BSP/RTC_Comm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659820069/KBD_5X8_rd.o: ../src/BSP/KBD_5X8_rd.c  .generated_files/flags/default/427e78924e9f33a356b17efa6a2b4ad0767963c9 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659820069" 
	@${RM} ${OBJECTDIR}/_ext/659820069/KBD_5X8_rd.o.d 
	@${RM} ${OBJECTDIR}/_ext/659820069/KBD_5X8_rd.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659820069/KBD_5X8_rd.o.d" -o ${OBJECTDIR}/_ext/659820069/KBD_5X8_rd.o ../src/BSP/KBD_5X8_rd.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659820069/LCD_Comm.o: ../src/BSP/LCD_Comm.c  .generated_files/flags/default/b041a79f9268107f201fcf344fc05a7cccc16009 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659820069" 
	@${RM} ${OBJECTDIR}/_ext/659820069/LCD_Comm.o.d 
	@${RM} ${OBJECTDIR}/_ext/659820069/LCD_Comm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659820069/LCD_Comm.o.d" -o ${OBJECTDIR}/_ext/659820069/LCD_Comm.o ../src/BSP/LCD_Comm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/60165182/plib_can1.o: ../src/config/default/peripheral/can/plib_can1.c  .generated_files/flags/default/113a85377646a9d721ba21c7c9b2d05d17c2fafc .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/60165182" 
	@${RM} ${OBJECTDIR}/_ext/60165182/plib_can1.o.d 
	@${RM} ${OBJECTDIR}/_ext/60165182/plib_can1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/60165182/plib_can1.o.d" -o ${OBJECTDIR}/_ext/60165182/plib_can1.o ../src/config/default/peripheral/can/plib_can1.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/60165520/plib_clk.o: ../src/config/default/peripheral/clk/plib_clk.c  .generated_files/flags/default/2fa11a240c94f7615af981771d9c53e00f7e8e54 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/60165520" 
	@${RM} ${OBJECTDIR}/_ext/60165520/plib_clk.o.d 
	@${RM} ${OBJECTDIR}/_ext/60165520/plib_clk.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/60165520/plib_clk.o.d" -o ${OBJECTDIR}/_ext/60165520/plib_clk.o ../src/config/default/peripheral/clk/plib_clk.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1249264884/plib_coretimer.o: ../src/config/default/peripheral/coretimer/plib_coretimer.c  .generated_files/flags/default/f24dc771d2c07b5eea5b80f23b690e7daac377a1 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/1249264884" 
	@${RM} ${OBJECTDIR}/_ext/1249264884/plib_coretimer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1249264884/plib_coretimer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1249264884/plib_coretimer.o.d" -o ${OBJECTDIR}/_ext/1249264884/plib_coretimer.o ../src/config/default/peripheral/coretimer/plib_coretimer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1865200349/plib_evic.o: ../src/config/default/peripheral/evic/plib_evic.c  .generated_files/flags/default/8db2c637b2cf54fd22ce44ac697376df0c876e71 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/1865200349" 
	@${RM} ${OBJECTDIR}/_ext/1865200349/plib_evic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865200349/plib_evic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1865200349/plib_evic.o.d" -o ${OBJECTDIR}/_ext/1865200349/plib_evic.o ../src/config/default/peripheral/evic/plib_evic.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1865254177/plib_gpio.o: ../src/config/default/peripheral/gpio/plib_gpio.c  .generated_files/flags/default/86019c170e826b83104fa6db392cb7b70e69a5b1 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/1865254177" 
	@${RM} ${OBJECTDIR}/_ext/1865254177/plib_gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865254177/plib_gpio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1865254177/plib_gpio.o.d" -o ${OBJECTDIR}/_ext/1865254177/plib_gpio.o ../src/config/default/peripheral/gpio/plib_gpio.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/513455433/plib_i2c2_master.o: ../src/config/default/peripheral/i2c/master/plib_i2c2_master.c  .generated_files/flags/default/cd40e7f82785698e01c990ebde1b8824404e5da6 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/513455433" 
	@${RM} ${OBJECTDIR}/_ext/513455433/plib_i2c2_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/513455433/plib_i2c2_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/513455433/plib_i2c2_master.o.d" -o ${OBJECTDIR}/_ext/513455433/plib_i2c2_master.o ../src/config/default/peripheral/i2c/master/plib_i2c2_master.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/298189674/plib_spi1_master.o: ../src/config/default/peripheral/spi/spi_master/plib_spi1_master.c  .generated_files/flags/default/d081c942700e4c0b947c6c2dc8cf236fd6af2a58 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/298189674" 
	@${RM} ${OBJECTDIR}/_ext/298189674/plib_spi1_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/298189674/plib_spi1_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/298189674/plib_spi1_master.o.d" -o ${OBJECTDIR}/_ext/298189674/plib_spi1_master.o ../src/config/default/peripheral/spi/spi_master/plib_spi1_master.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1865657120/plib_uart3.o: ../src/config/default/peripheral/uart/plib_uart3.c  .generated_files/flags/default/4c403b48517324e0d6473d112d54eb87c79283b .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/1865657120" 
	@${RM} ${OBJECTDIR}/_ext/1865657120/plib_uart3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865657120/plib_uart3.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1865657120/plib_uart3.o.d" -o ${OBJECTDIR}/_ext/1865657120/plib_uart3.o ../src/config/default/peripheral/uart/plib_uart3.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1865657120/plib_uart1.o: ../src/config/default/peripheral/uart/plib_uart1.c  .generated_files/flags/default/b5fbda089b5735b85fb1c140d3075bea0991c730 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/1865657120" 
	@${RM} ${OBJECTDIR}/_ext/1865657120/plib_uart1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865657120/plib_uart1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1865657120/plib_uart1.o.d" -o ${OBJECTDIR}/_ext/1865657120/plib_uart1.o ../src/config/default/peripheral/uart/plib_uart1.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1865657120/plib_uart5.o: ../src/config/default/peripheral/uart/plib_uart5.c  .generated_files/flags/default/46341bb6ccf0183849d93a97bcdfc2b3775ded2b .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/1865657120" 
	@${RM} ${OBJECTDIR}/_ext/1865657120/plib_uart5.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865657120/plib_uart5.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1865657120/plib_uart5.o.d" -o ${OBJECTDIR}/_ext/1865657120/plib_uart5.o ../src/config/default/peripheral/uart/plib_uart5.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/163028504/xc32_monitor.o: ../src/config/default/stdio/xc32_monitor.c  .generated_files/flags/default/ebf5e95181bad6d0cf35c397e1e38ddcf97bb243 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/163028504" 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ../src/config/default/stdio/xc32_monitor.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1171490990/initialization.o: ../src/config/default/initialization.c  .generated_files/flags/default/2ff31da619b3c418148ed2ef47ed0b10ed7ee329 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/initialization.o.d" -o ${OBJECTDIR}/_ext/1171490990/initialization.o ../src/config/default/initialization.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1171490990/interrupts.o: ../src/config/default/interrupts.c  .generated_files/flags/default/63e21528a6870fa163e0eaa0f5f59e11ebf2cb55 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/interrupts.o.d" -o ${OBJECTDIR}/_ext/1171490990/interrupts.o ../src/config/default/interrupts.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1171490990/exceptions.o: ../src/config/default/exceptions.c  .generated_files/flags/default/16085b387cb45f526f385dd5103a40b9fb667a22 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/exceptions.o.d" -o ${OBJECTDIR}/_ext/1171490990/exceptions.o ../src/config/default/exceptions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1549516009/BCD_Utils.o: ../src/Utils/BCD_Utils.c  .generated_files/flags/default/f790b0bcbe192ea642010e99b7186a64da263f6b .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/1549516009" 
	@${RM} ${OBJECTDIR}/_ext/1549516009/BCD_Utils.o.d 
	@${RM} ${OBJECTDIR}/_ext/1549516009/BCD_Utils.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1549516009/BCD_Utils.o.d" -o ${OBJECTDIR}/_ext/1549516009/BCD_Utils.o ../src/Utils/BCD_Utils.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1549516009/Utils.o: ../src/Utils/Utils.c  .generated_files/flags/default/ac979cd1efa261f5dd4d8584156e263f8a6d278f .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/1549516009" 
	@${RM} ${OBJECTDIR}/_ext/1549516009/Utils.o.d 
	@${RM} ${OBJECTDIR}/_ext/1549516009/Utils.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1549516009/Utils.o.d" -o ${OBJECTDIR}/_ext/1549516009/Utils.o ../src/Utils/Utils.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/3d7440ca76b8606446c4a8f8952001abb5f2473 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/App_Protocol.o: ../src/App_Protocol.c  .generated_files/flags/default/d769c1c0865fb12687403217374759b9ad744cae .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/App_Protocol.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/App_Protocol.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/App_Protocol.o.d" -o ${OBJECTDIR}/_ext/1360937237/App_Protocol.o ../src/App_Protocol.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/60163342/plib_adc.o: ../src/config/default/peripheral/adc/plib_adc.c  .generated_files/flags/default/9fea2b01a36aa644af52a467dab1f4ff202ed595 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/60163342" 
	@${RM} ${OBJECTDIR}/_ext/60163342/plib_adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/60163342/plib_adc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/60163342/plib_adc.o.d" -o ${OBJECTDIR}/_ext/60163342/plib_adc.o ../src/config/default/peripheral/adc/plib_adc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/_ext/659819008/Amplifier_Com.o: ../src/API/Amplifier_Com.c  .generated_files/flags/default/4f6ed8c5ac07b2ec3c4227e2198ab59750ec7cf6 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659819008" 
	@${RM} ${OBJECTDIR}/_ext/659819008/Amplifier_Com.o.d 
	@${RM} ${OBJECTDIR}/_ext/659819008/Amplifier_Com.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659819008/Amplifier_Com.o.d" -o ${OBJECTDIR}/_ext/659819008/Amplifier_Com.o ../src/API/Amplifier_Com.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659819008/CAN_Enco_Com.o: ../src/API/CAN_Enco_Com.c  .generated_files/flags/default/64d89690eb901085439c7142fa6afb95611bf939 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659819008" 
	@${RM} ${OBJECTDIR}/_ext/659819008/CAN_Enco_Com.o.d 
	@${RM} ${OBJECTDIR}/_ext/659819008/CAN_Enco_Com.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659819008/CAN_Enco_Com.o.d" -o ${OBJECTDIR}/_ext/659819008/CAN_Enco_Com.o ../src/API/CAN_Enco_Com.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659819008/Global_Vars.o: ../src/API/Global_Vars.c  .generated_files/flags/default/6637a33e29d68ebe09524f348ace2b30dbda38a4 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659819008" 
	@${RM} ${OBJECTDIR}/_ext/659819008/Global_Vars.o.d 
	@${RM} ${OBJECTDIR}/_ext/659819008/Global_Vars.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659819008/Global_Vars.o.d" -o ${OBJECTDIR}/_ext/659819008/Global_Vars.o ../src/API/Global_Vars.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659819008/Protocol.o: ../src/API/Protocol.c  .generated_files/flags/default/23352da1b777914c8eed7c29ed43e6f06bf28446 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659819008" 
	@${RM} ${OBJECTDIR}/_ext/659819008/Protocol.o.d 
	@${RM} ${OBJECTDIR}/_ext/659819008/Protocol.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659819008/Protocol.o.d" -o ${OBJECTDIR}/_ext/659819008/Protocol.o ../src/API/Protocol.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659819008/Ampli_functions.o: ../src/API/Ampli_functions.c  .generated_files/flags/default/3f39db0e3aec87a59883f066a6e48f06ad4a4a85 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659819008" 
	@${RM} ${OBJECTDIR}/_ext/659819008/Ampli_functions.o.d 
	@${RM} ${OBJECTDIR}/_ext/659819008/Ampli_functions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659819008/Ampli_functions.o.d" -o ${OBJECTDIR}/_ext/659819008/Ampli_functions.o ../src/API/Ampli_functions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659819008/AtmelFlashMem.o: ../src/API/AtmelFlashMem.c  .generated_files/flags/default/66be8d325617e61219c06bba61d8a675ac8ab43e .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659819008" 
	@${RM} ${OBJECTDIR}/_ext/659819008/AtmelFlashMem.o.d 
	@${RM} ${OBJECTDIR}/_ext/659819008/AtmelFlashMem.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659819008/AtmelFlashMem.o.d" -o ${OBJECTDIR}/_ext/659819008/AtmelFlashMem.o ../src/API/AtmelFlashMem.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659819008/BoardTemp.o: ../src/API/BoardTemp.c  .generated_files/flags/default/1f3e76ca3785efca549f22e5d73a0e49985b26b1 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659819008" 
	@${RM} ${OBJECTDIR}/_ext/659819008/BoardTemp.o.d 
	@${RM} ${OBJECTDIR}/_ext/659819008/BoardTemp.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659819008/BoardTemp.o.d" -o ${OBJECTDIR}/_ext/659819008/BoardTemp.o ../src/API/BoardTemp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659819008/RTC.o: ../src/API/RTC.c  .generated_files/flags/default/2d2f2b3f905d3500c0945e753eaa3455cf2b9 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659819008" 
	@${RM} ${OBJECTDIR}/_ext/659819008/RTC.o.d 
	@${RM} ${OBJECTDIR}/_ext/659819008/RTC.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659819008/RTC.o.d" -o ${OBJECTDIR}/_ext/659819008/RTC.o ../src/API/RTC.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659819008/KBD_5X8.o: ../src/API/KBD_5X8.c  .generated_files/flags/default/bd387936459e75e9f6a121b37dd9077917004ea5 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659819008" 
	@${RM} ${OBJECTDIR}/_ext/659819008/KBD_5X8.o.d 
	@${RM} ${OBJECTDIR}/_ext/659819008/KBD_5X8.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659819008/KBD_5X8.o.d" -o ${OBJECTDIR}/_ext/659819008/KBD_5X8.o ../src/API/KBD_5X8.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659819008/LCD_functions.o: ../src/API/LCD_functions.c  .generated_files/flags/default/41d264eb52d7db6a35e06ede0b052625d366ff48 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659819008" 
	@${RM} ${OBJECTDIR}/_ext/659819008/LCD_functions.o.d 
	@${RM} ${OBJECTDIR}/_ext/659819008/LCD_functions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659819008/LCD_functions.o.d" -o ${OBJECTDIR}/_ext/659819008/LCD_functions.o ../src/API/LCD_functions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659820069/CAN_Comm.o: ../src/BSP/CAN_Comm.c  .generated_files/flags/default/6f5901664ee55bb2ec19242f78cd8ea59d9b81fb .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659820069" 
	@${RM} ${OBJECTDIR}/_ext/659820069/CAN_Comm.o.d 
	@${RM} ${OBJECTDIR}/_ext/659820069/CAN_Comm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659820069/CAN_Comm.o.d" -o ${OBJECTDIR}/_ext/659820069/CAN_Comm.o ../src/BSP/CAN_Comm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659820069/Events.o: ../src/BSP/Events.c  .generated_files/flags/default/7a37b070e4a8204658ecc2029aad5cc9735f660 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659820069" 
	@${RM} ${OBJECTDIR}/_ext/659820069/Events.o.d 
	@${RM} ${OBJECTDIR}/_ext/659820069/Events.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659820069/Events.o.d" -o ${OBJECTDIR}/_ext/659820069/Events.o ../src/BSP/Events.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659820069/ETH_Module_Com.o: ../src/BSP/ETH_Module_Com.c  .generated_files/flags/default/f54ac2965a30f5fa6c6efe26af7823ff49d65678 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659820069" 
	@${RM} ${OBJECTDIR}/_ext/659820069/ETH_Module_Com.o.d 
	@${RM} ${OBJECTDIR}/_ext/659820069/ETH_Module_Com.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659820069/ETH_Module_Com.o.d" -o ${OBJECTDIR}/_ext/659820069/ETH_Module_Com.o ../src/BSP/ETH_Module_Com.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659820069/SSI_Enco.o: ../src/BSP/SSI_Enco.c  .generated_files/flags/default/885084eead96fac2c5c8a34806be0c1f50870a95 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659820069" 
	@${RM} ${OBJECTDIR}/_ext/659820069/SSI_Enco.o.d 
	@${RM} ${OBJECTDIR}/_ext/659820069/SSI_Enco.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659820069/SSI_Enco.o.d" -o ${OBJECTDIR}/_ext/659820069/SSI_Enco.o ../src/BSP/SSI_Enco.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659820069/Beeps.o: ../src/BSP/Beeps.c  .generated_files/flags/default/c031181400e7a1dc21dd69beb26bf5e9f27ce931 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659820069" 
	@${RM} ${OBJECTDIR}/_ext/659820069/Beeps.o.d 
	@${RM} ${OBJECTDIR}/_ext/659820069/Beeps.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659820069/Beeps.o.d" -o ${OBJECTDIR}/_ext/659820069/Beeps.o ../src/BSP/Beeps.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659820069/DataFlash_Comm.o: ../src/BSP/DataFlash_Comm.c  .generated_files/flags/default/dcf58db567a16f21132a500f99e5084381ee6112 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659820069" 
	@${RM} ${OBJECTDIR}/_ext/659820069/DataFlash_Comm.o.d 
	@${RM} ${OBJECTDIR}/_ext/659820069/DataFlash_Comm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659820069/DataFlash_Comm.o.d" -o ${OBJECTDIR}/_ext/659820069/DataFlash_Comm.o ../src/BSP/DataFlash_Comm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659820069/I2C_comm.o: ../src/BSP/I2C_comm.c  .generated_files/flags/default/aefcc9072c424f81e9b9e71539d2f54f5ad45849 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659820069" 
	@${RM} ${OBJECTDIR}/_ext/659820069/I2C_comm.o.d 
	@${RM} ${OBJECTDIR}/_ext/659820069/I2C_comm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659820069/I2C_comm.o.d" -o ${OBJECTDIR}/_ext/659820069/I2C_comm.o ../src/BSP/I2C_comm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659820069/RTC_Comm.o: ../src/BSP/RTC_Comm.c  .generated_files/flags/default/b6d08a17b21a3823c94555325bacb4b191220bc7 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659820069" 
	@${RM} ${OBJECTDIR}/_ext/659820069/RTC_Comm.o.d 
	@${RM} ${OBJECTDIR}/_ext/659820069/RTC_Comm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659820069/RTC_Comm.o.d" -o ${OBJECTDIR}/_ext/659820069/RTC_Comm.o ../src/BSP/RTC_Comm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659820069/KBD_5X8_rd.o: ../src/BSP/KBD_5X8_rd.c  .generated_files/flags/default/3945d9472eac5f2518ab893e9ce218c1e42f1e3b .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659820069" 
	@${RM} ${OBJECTDIR}/_ext/659820069/KBD_5X8_rd.o.d 
	@${RM} ${OBJECTDIR}/_ext/659820069/KBD_5X8_rd.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659820069/KBD_5X8_rd.o.d" -o ${OBJECTDIR}/_ext/659820069/KBD_5X8_rd.o ../src/BSP/KBD_5X8_rd.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/659820069/LCD_Comm.o: ../src/BSP/LCD_Comm.c  .generated_files/flags/default/f3a9c3fae984c4bcc58cd077d3959df393f8a49f .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/659820069" 
	@${RM} ${OBJECTDIR}/_ext/659820069/LCD_Comm.o.d 
	@${RM} ${OBJECTDIR}/_ext/659820069/LCD_Comm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/659820069/LCD_Comm.o.d" -o ${OBJECTDIR}/_ext/659820069/LCD_Comm.o ../src/BSP/LCD_Comm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/60165182/plib_can1.o: ../src/config/default/peripheral/can/plib_can1.c  .generated_files/flags/default/29bc71f0a4fa287e1e0e60128940bd8001c8e914 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/60165182" 
	@${RM} ${OBJECTDIR}/_ext/60165182/plib_can1.o.d 
	@${RM} ${OBJECTDIR}/_ext/60165182/plib_can1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/60165182/plib_can1.o.d" -o ${OBJECTDIR}/_ext/60165182/plib_can1.o ../src/config/default/peripheral/can/plib_can1.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/60165520/plib_clk.o: ../src/config/default/peripheral/clk/plib_clk.c  .generated_files/flags/default/7f239dfa833a0b9ed65d068e1f603d8d78578b52 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/60165520" 
	@${RM} ${OBJECTDIR}/_ext/60165520/plib_clk.o.d 
	@${RM} ${OBJECTDIR}/_ext/60165520/plib_clk.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/60165520/plib_clk.o.d" -o ${OBJECTDIR}/_ext/60165520/plib_clk.o ../src/config/default/peripheral/clk/plib_clk.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1249264884/plib_coretimer.o: ../src/config/default/peripheral/coretimer/plib_coretimer.c  .generated_files/flags/default/212c262220b7024950030fd2ac1706a6fd76bc4e .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/1249264884" 
	@${RM} ${OBJECTDIR}/_ext/1249264884/plib_coretimer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1249264884/plib_coretimer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1249264884/plib_coretimer.o.d" -o ${OBJECTDIR}/_ext/1249264884/plib_coretimer.o ../src/config/default/peripheral/coretimer/plib_coretimer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1865200349/plib_evic.o: ../src/config/default/peripheral/evic/plib_evic.c  .generated_files/flags/default/cec4384ddc0b81b6b690ed96733a88064edcbafa .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/1865200349" 
	@${RM} ${OBJECTDIR}/_ext/1865200349/plib_evic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865200349/plib_evic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1865200349/plib_evic.o.d" -o ${OBJECTDIR}/_ext/1865200349/plib_evic.o ../src/config/default/peripheral/evic/plib_evic.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1865254177/plib_gpio.o: ../src/config/default/peripheral/gpio/plib_gpio.c  .generated_files/flags/default/5b5837030f7cbd5fa3c01d2b67ea42621c971049 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/1865254177" 
	@${RM} ${OBJECTDIR}/_ext/1865254177/plib_gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865254177/plib_gpio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1865254177/plib_gpio.o.d" -o ${OBJECTDIR}/_ext/1865254177/plib_gpio.o ../src/config/default/peripheral/gpio/plib_gpio.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/513455433/plib_i2c2_master.o: ../src/config/default/peripheral/i2c/master/plib_i2c2_master.c  .generated_files/flags/default/b66a93772f6b171b3802a2f5b5195d907abf8d3d .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/513455433" 
	@${RM} ${OBJECTDIR}/_ext/513455433/plib_i2c2_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/513455433/plib_i2c2_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/513455433/plib_i2c2_master.o.d" -o ${OBJECTDIR}/_ext/513455433/plib_i2c2_master.o ../src/config/default/peripheral/i2c/master/plib_i2c2_master.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/298189674/plib_spi1_master.o: ../src/config/default/peripheral/spi/spi_master/plib_spi1_master.c  .generated_files/flags/default/77df14bb7b649d80e001d8f03766decc7cfd48ef .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/298189674" 
	@${RM} ${OBJECTDIR}/_ext/298189674/plib_spi1_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/298189674/plib_spi1_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/298189674/plib_spi1_master.o.d" -o ${OBJECTDIR}/_ext/298189674/plib_spi1_master.o ../src/config/default/peripheral/spi/spi_master/plib_spi1_master.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1865657120/plib_uart3.o: ../src/config/default/peripheral/uart/plib_uart3.c  .generated_files/flags/default/3ccd7e43d671416dbf80f3b8039a5586e8a2415d .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/1865657120" 
	@${RM} ${OBJECTDIR}/_ext/1865657120/plib_uart3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865657120/plib_uart3.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1865657120/plib_uart3.o.d" -o ${OBJECTDIR}/_ext/1865657120/plib_uart3.o ../src/config/default/peripheral/uart/plib_uart3.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1865657120/plib_uart1.o: ../src/config/default/peripheral/uart/plib_uart1.c  .generated_files/flags/default/1cf0df93edb9c77d8421d1443193bdba43993e18 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/1865657120" 
	@${RM} ${OBJECTDIR}/_ext/1865657120/plib_uart1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865657120/plib_uart1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1865657120/plib_uart1.o.d" -o ${OBJECTDIR}/_ext/1865657120/plib_uart1.o ../src/config/default/peripheral/uart/plib_uart1.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1865657120/plib_uart5.o: ../src/config/default/peripheral/uart/plib_uart5.c  .generated_files/flags/default/6eecb11a268f258b5ad79926b9deafa58aa17eff .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/1865657120" 
	@${RM} ${OBJECTDIR}/_ext/1865657120/plib_uart5.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865657120/plib_uart5.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1865657120/plib_uart5.o.d" -o ${OBJECTDIR}/_ext/1865657120/plib_uart5.o ../src/config/default/peripheral/uart/plib_uart5.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/163028504/xc32_monitor.o: ../src/config/default/stdio/xc32_monitor.c  .generated_files/flags/default/5dfd4b0f72607d094c14ab30b1ed877558c2ad3f .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/163028504" 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ../src/config/default/stdio/xc32_monitor.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1171490990/initialization.o: ../src/config/default/initialization.c  .generated_files/flags/default/7e7c7b53210a0b893bf5d3942ab6d3a9ebf64d2c .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/initialization.o.d" -o ${OBJECTDIR}/_ext/1171490990/initialization.o ../src/config/default/initialization.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1171490990/interrupts.o: ../src/config/default/interrupts.c  .generated_files/flags/default/b2a4e9178045ac25944f601abb2707c5957d5237 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/interrupts.o.d" -o ${OBJECTDIR}/_ext/1171490990/interrupts.o ../src/config/default/interrupts.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1171490990/exceptions.o: ../src/config/default/exceptions.c  .generated_files/flags/default/3e1c9777f0da131d75569642d6706ec9694d8dd3 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/exceptions.o.d" -o ${OBJECTDIR}/_ext/1171490990/exceptions.o ../src/config/default/exceptions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1549516009/BCD_Utils.o: ../src/Utils/BCD_Utils.c  .generated_files/flags/default/a33c5ea88dbc306bc7915b0210fde845dbc0c561 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/1549516009" 
	@${RM} ${OBJECTDIR}/_ext/1549516009/BCD_Utils.o.d 
	@${RM} ${OBJECTDIR}/_ext/1549516009/BCD_Utils.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1549516009/BCD_Utils.o.d" -o ${OBJECTDIR}/_ext/1549516009/BCD_Utils.o ../src/Utils/BCD_Utils.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1549516009/Utils.o: ../src/Utils/Utils.c  .generated_files/flags/default/a648f84344e0e8d6001406f9ddeb5c4c8cfb8d3c .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/1549516009" 
	@${RM} ${OBJECTDIR}/_ext/1549516009/Utils.o.d 
	@${RM} ${OBJECTDIR}/_ext/1549516009/Utils.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1549516009/Utils.o.d" -o ${OBJECTDIR}/_ext/1549516009/Utils.o ../src/Utils/Utils.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/f25d6b0a7bfb4f066db83f7bd75c3035cf5bedef .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/App_Protocol.o: ../src/App_Protocol.c  .generated_files/flags/default/829a2b71c0b176c575d72b4fc63ab7c901c35cd0 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/App_Protocol.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/App_Protocol.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/App_Protocol.o.d" -o ${OBJECTDIR}/_ext/1360937237/App_Protocol.o ../src/App_Protocol.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/60163342/plib_adc.o: ../src/config/default/peripheral/adc/plib_adc.c  .generated_files/flags/default/c9ccb0d6a6e5e1e7d950004a69124766fb913659 .generated_files/flags/default/a9c43a72845009ca478a0bc594dda789b623f82
	@${MKDIR} "${OBJECTDIR}/_ext/60163342" 
	@${RM} ${OBJECTDIR}/_ext/60163342/plib_adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/60163342/plib_adc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src" -I"../src/BSP" -I"../src/API" -I"../src/Utils" -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/default" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/60163342/plib_adc.o.d" -o ${OBJECTDIR}/_ext/60163342/plib_adc.o ../src/config/default/peripheral/adc/plib_adc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/BEPL_T.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../src/config/default/p32MX795F512L.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/BEPL_T.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=512,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/BEPL_T.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../src/config/default/p32MX795F512L.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/BEPL_T.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wno-missing-braces  -Wno-pointer-sign -Wno-uninitialized -Wno-unused-but-set-variable -Wno-unused-variable -Wno-implicit-function-declaration $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=512,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/BEPL_T.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
