Name: libomxil-e3250-v4l2
Summary: OpenMAX IL for e3250-v4l2
Version: 0.0.16
License: TO BE FILLED IN
Group: Development/Libraries
Release: 0
ExclusiveArch: %arm
Source: %{name}-%{version}.tar.gz
Requires(post): /sbin/ldconfig
Requires(postun): /sbin/ldconfig
BuildRequires: kernel-headers
BuildRequires:  pkgconfig(dlog)
BuildRequires: pkgconfig(mm-common)

%description
implementation of OpenMAX IL for e3250-v4l2 for B2


%package devel
Summary: OpenMAX IL for e3250-v4l2 (Developement)
Group: Development/Libraries
Requires: %{name} = %{version}-%{release}

%description devel
development package for libomxil-e3250-v4l2

%prep
%setup -q

%build
./autogen.sh

export CFLAGS+="\
%ifnarch aarch64
 -mfpu=neon\
 -DUSE_NEON\
%endif
 -DUSE_PB\
 -DUSE_DMA_BUF\
 -DUSE_H264_PREPEND_SPS_PPS\
 -DGST_EXT_TIME_ANALYSIS\
 -DKERNEL_HEADER_MODIFICATION"

%ifnarch aarch64
%configure --prefix=%{_prefix} --disable-static --enable-dlog --enable-exynos3250 --enable-neon
%else
%configure --prefix=%{_prefix} --disable-static --enable-dlog --enable-exynos3250 --disable-neon
%endif

#make %{?jobs:-j%jobs}
make


%install
rm -rf %{buildroot}
#mkdir -p %{buildroot}/usr/share/license
#cp COPYING %{buildroot}/usr/share/license/%{name}
%make_install


%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig


%files
%manifest libomxil-e3250-v4l2.manifest
%{_libdir}/*.so*
%{_libdir}/omx/*.so


%files devel
/usr/include/*
%{_libdir}/pkgconfig/*

