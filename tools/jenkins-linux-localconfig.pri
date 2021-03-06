# Template for a custom configuration
# You should not need this if you have all dependencies in the right
# directories or you are using Debian GNU/Linux.
#
# The only variable that is defined before is BASEDIR

# Uncomment for release version
#RELEASE = 1

# Uncomment if nmake has trouble with long command lines
# CLEBS *= nosilent

# Uncomment to override make files that want precompiled headers
CLEBS -= pch

# Disable matlab filter as it gives problems with clang
CLEBS_DISABLED *= src/plugins/matlabfilter

# Use multiple cores in windows
#win32:QMAKE_CXXFLAGS += /MP2


# Dependencies for Unix:
unix:MATLABROOT=/opt/matlab
#unix:IOWKITROOT=/usr/local

# Dependencies for Windows
#win32:XALANCROOT = $$BASEDIR/../api/xalan
#win32:XALANCLIB = xalan-c_1
#win32:XALANCLIB_RELEASE = $${XALANCLIB}
#win32:XALANCLIB_DEBUG = $${XALANCLIB}d
#win32:XALANCLIBDIR = $${XALANCROOT}/build/win32/vc7.1
#win32:XALANCLIBDIR_RELEASE = $${XALANCLIBDIR}/release
#win32:XALANCLIBDIR_DEBUG = $${XALANCLIBDIR}/debug
#win32:XALANCDLLS = xalan-c_1_10 xalanmessages_1_10
#win32:for(i,XALANCDLLS):XALANCDLLS_RELEASE *= $${i}.dll
#win32:for(i,XALANCDLLS):XALANCDLLS_DEBUG *= $${i}d.dll
#win32:XALANCDLLDIR = $${XALANCLIBDIR}
#win32:XALANCDLLDIR_RELEASE = $${XALANCDLLDIR}/release
#win32:XALANCDLLDIR_DEBUG = $${XALANCDLLDIR}/debug
#win32:XALANCINCLUDEDIR = $${XALANCROOT}/src

#win32:PORTAUDIOROOT = $$BASEDIR/../api/portaudio
#win32:PORTAUDIOLIB = portaudio_x86
#win32:PORTAUDIOLIB_RELEASE = $${PORTAUDIOLIB}
#win32:PORTAUDIOLIB_DEBUG = $${PORTAUDIOLIB}
#win32:PORTAUDIOLIBDIR = $${PORTAUDIOROOT}/lib
#win32:PORTAUDIOLIBDIR_RELEASE = $${PORTAUDIOLIBDIR}/release
#win32:PORTAUDIOLIBDIR_DEBUG = $${PORTAUDIOLIBDIR}/debug
#win32:PORTAUDIOINCLUDEDIR = $${PORTAUDIOROOT}/include

#win32:NUCLEUSROOT = $$BASEDIR/../api/nucleus
#win32:NUCLEUSLIBDIR = $${NUCLEUSROOT}/libraries/msvc/v7.1
#win32:NUCLEUSINCLUDEDIR = $${NUCLEUSROOT}/include

#win32:FFTW3ROOT = $$BASEDIR/../api/fftw3
#win32:FFTW3LIB = libfftw3-3
#win32:FFTW3LIB_RELEASE = $${FFTW3LIB}
#win32:FFTW3LIB_DEBUG = $${FFTW3LIB}
#win32:FFTW3LIBDIR = $${FFTW3ROOT}
#win32:FFTW3LIBDIR_RELEASE = $${FFTW3LIBDIR}
#win32:FFTW3LIBDIR_DEBUG = $${FFTW3LIBDIR}
#win32:FFTW3INCLUDEDIR = $${FFTW3ROOT}

#win32:FFTW3FROOT = $$BASEDIR/../api/fftw3
#win32:FFTW3FLIB = libfftw3f-3
#win32:FFTW3FLIB_RELEASE = $${FFTW3FLIB}
#win32:FFTW3FLIB_DEBUG = $${FFTW3FLIB}
#win32:FFTW3FLIBDIR = $${FFTW3FROOT}
#win32:FFTW3FLIBDIR_RELEASE = $${FFTW3FLIBDIR}
#win32:FFTW3FLIBDIR_DEBUG = $${FFTW3FLIBDIR}
#win32:FFTW3FINCLUDEDIR = $${FFTW3FROOT}

# Boost
#isEmpty(BOOSTROOT):BOOSTROOT = $$BASEDIR/../api/boost
#isEmpty(BOOSTINCLUDEDIR):BOOSTINCLUDEDIR = $${BOOSTROOT}/include/boost-1_37
#isEmpty(BOOSTLIBDIR):BOOSTLIBDIR = $${BOOSTROOT}/lib
#isEmpty(BOOSTLIBDIR_RELEASE):BOOSTLIBDIR_RELEASE = $${BOOSTLIBDIR}
#isEmpty(BOOSTLIBDIR_DEBUG):BOOSTLIBDIR_DEBUG = $${BOOSTLIBDIR}
#isEmpty(BOOSTPOLIB_RELEASE):BOOSTPOLIB_RELEASE = boost_program_options-vc90-mt-1_37
#isEmpty(BOOSTPOLIB_DEBUG):BOOSTPOLIB_DEBUG = boost_program_options-vc90-mt-gd-1_37


#win32:ASIOROOT = $$BASEDIR/../api/asio
#win32:SNDFILEROOT = $$BASEDIR/../api/sndfile
#win32:IOWKITROOT= $$BASEDIR/../api/iowkit

#win32:PROTOBUFROOT = $$BASEDIR/../api/protobuf
#win32:PROTOBUFLIB = libprotobuf-lite
#win32:PROTOBUFLIB_RELEASE = $${PROTOBUFLIB}
#win32:PROTOBUFLIB_DEBUG = $${PROTOBUFLIB}
#win32:PROTOBUFLIB_VERSION = -8
#win32:PROTOBUFLIBDIR = $${PROTOBUFROOT}
#win32:PROTOBUFLIBDIR_RELEASE = $${PROTOBUFLIBDIR}/release
#win32:PROTOBUFLIBDIR_DEBUG = $${PROTOBUFLIBDIR}/debug
#win32:PROTOBUFINCLUDEDIR = $${PROTOBUFROOT}/include
#win32:PROTOBUFPROTOC = $${PROTOBUFROOT}/protoc.exe
#win32:PROTOBUFPYTHONDIR = $${PROTOBUFROOT}/python-lib

#win32:NIC3ROOT = $$BASEDIR/../api/nic3
#win32:NIC3BINARIESDIR = $$NIC3ROOT/binaries
#win32:NIC3PYTHONDIR = $$NIC3ROOT/python

# Installation paths for Unix
#unix:PREFIXDIR = /usr/local
#unix:CONFDIR = /etc
#unix:DATADIR = $$PREFIXDIR/share/apex
#unix:APPDIR = $$PREFIXDIR/share/applications
#unix:ICONDIR = $$PREFIXDIR/share/icons/hicolor
#unix:BINDIR = $$PREFIXDIR/bin
#unix:LIBDIR = $$PREFIXDIR/lib
#unix:PLUGINDIR = $$PREFIXDIR/lib/apex

# Installation paths for Windows
#win32:PREFIXDIR = $${DESTDIR}_installed
#win32:CONFDIR = $$PREFIXDIR/config
#win32:DATADIR = $$PREFIXDIR
#win32:ICONDIR = $$PREFIXDIR/icons
#win32:BINDIR = $$PREFIXDIR/bin
#win32:LIBDIR = $$PREFIXDIR/bin
#win32:PLUGINDIR = $$PREFIXDIR/plugins

# Streamapp
#CONFIG += MAC         #use OsX config
