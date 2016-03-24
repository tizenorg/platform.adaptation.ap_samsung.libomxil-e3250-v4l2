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
#!BuildIgnore: kernel-headers
BuildRequires:  kernel-headers-3.4-exynos3250
BuildRequires:  pkgconfig(dlog)
BuildRequires:  pkgconfig(mm-ta)

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

export CFLAGS+=" -mfpu=neon\
 -DUSE_DLOG\
 -DUSE_PB\
 -DUSE_DMA_BUF\
 -DUSE_H264_PREPEND_SPS_PPS\
 -DGST_EXT_TIME_ANALYSIS"

%configure --prefix=%{_prefix} --disable-static --enable-dlog --enable-mm-ta --enable-exynos3250

#make %{?jobs:-j%jobs}
make


%install
rm -rf %{buildroot}
mkdir -p %{buildroot}/usr/share/license
cp COPYING %{buildroot}/usr/share/license/%{name}
%make_install


%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig


%files
%manifest libomxil-e3250-v4l2.manifest
/usr/lib/*.so*
/usr/lib/omx/libOMX.Exynos.AVC.Decoder.so
/usr/lib/omx/libOMX.Exynos.AVC.Encoder.so
/usr/lib/omx/libOMX.Exynos.M4V.Decoder.so
/usr/share/license/%{name}
%exclude /usr/lib/omx/libOMX.Exynos.M2V.Decoder.so
%exclude /usr/lib/omx/libOMX.Exynos.WMV.Decoder.so
%exclude /usr/lib/omx/libOMX.Exynos.M4V.Encoder.so
%exclude /usr/lib/omx/libOMX.Exynos.MP3.Decoder.so

%files devel
/usr/include/*
/usr/lib/pkgconfig/*

