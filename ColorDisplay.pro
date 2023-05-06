QMAKE_CXX                       = @echo "Compiling $@" && g++
QMAKE_LINK                      = @echo "Linking $@" && g++
QMAKE_MOC                       = @echo "Creating  $@" && $$[QT_INSTALL_BINS]$${DIR_SEPARATOR}moc.exe
QMAKE_LFLAGS_WINDOWS            = -Wl,-subsystem,windows

QMAKE_CXXFLAGS                  += -g -Werror

TARGET                          = colordisplay

QT                              += core gui widgets

SOURCES                         += \
				   ColorFrame.cpp                               \
				   ControlsFrame.cpp                            \
				   DisplayFrame.cpp                             \
				   GradientColorFrame.cpp                       \
				   MainDisplayWindow.cpp                        \
				   MainWindow.cpp                               \
				   SimpleColorFrame.cpp                         \
				   main.cpp                                     \

HEADERS                         += \
				   ColorFrame.h                                 \
				   ControlsFrame.h                              \
				   DisplayFrame.h                               \
				   GradientColorFrame.h                         \
				   MainDisplayWindow.h                          \
				   MainWindow.h                                 \
				   SimpleColorFrame.h                           \

FORMS                           += \

QMAKE_EXTRA_TARGETS             += junkclean
junkclean.target                = junkclean
junkclean.commands              = @echo Removing junk                           \
                                  && rm -rf $(wildcard core* *~)
junkclean.depends               = 

QMAKE_EXTRA_TARGETS             += cleanall
cleanall.target                 = cleanall
cleanall.commands               = 
cleanall.depends                = junkclean                                     \
                                  clean
