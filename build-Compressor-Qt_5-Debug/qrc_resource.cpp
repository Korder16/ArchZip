/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.2.1
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtCore/qglobal.h>

static const unsigned char qt_resource_data[] = {
  // /home/pc/QtProjects/Compressor/Compressor/config/settings.conf
  0x0,0x0,0x0,0xd3,
  0x66,
  0x69,0x6c,0x65,0x73,0x5f,0x74,0x6f,0x5f,0x63,0x6f,0x6d,0x70,0x72,0x65,0x73,0x73,
  0x5f,0x64,0x69,0x72,0x3d,0x2f,0x68,0x6f,0x6d,0x65,0x2f,0x70,0x63,0x2f,0x51,0x74,
  0x50,0x72,0x6f,0x6a,0x65,0x63,0x74,0x73,0x2f,0x43,0x6f,0x6d,0x70,0x72,0x65,0x73,
  0x73,0x6f,0x72,0x2f,0x46,0x69,0x6c,0x65,0x73,0x20,0x74,0x6f,0x20,0x63,0x6f,0x6d,
  0x70,0x72,0x65,0x73,0x73,0x2f,0xa,0x63,0x6f,0x6d,0x70,0x72,0x65,0x73,0x73,0x65,
  0x64,0x5f,0x66,0x69,0x6c,0x65,0x73,0x5f,0x64,0x69,0x72,0x3d,0x2f,0x68,0x6f,0x6d,
  0x65,0x2f,0x70,0x63,0x2f,0x51,0x74,0x50,0x72,0x6f,0x6a,0x65,0x63,0x74,0x73,0x2f,
  0x43,0x6f,0x6d,0x70,0x72,0x65,0x73,0x73,0x6f,0x72,0x2f,0x43,0x6f,0x6d,0x70,0x72,
  0x65,0x73,0x73,0x65,0x64,0x20,0x66,0x69,0x6c,0x65,0x73,0x2f,0xa,0x63,0x6f,0x6d,
  0x70,0x72,0x65,0x73,0x73,0x69,0x6f,0x6e,0x5f,0x6c,0x6f,0x67,0x73,0x5f,0x64,0x69,
  0x72,0x3d,0x2f,0x68,0x6f,0x6d,0x65,0x2f,0x70,0x63,0x2f,0x51,0x74,0x50,0x72,0x6f,
  0x6a,0x65,0x63,0x74,0x73,0x2f,0x43,0x6f,0x6d,0x70,0x72,0x65,0x73,0x73,0x6f,0x72,
  0x2f,0x43,0x6f,0x6d,0x70,0x72,0x65,0x73,0x73,0x69,0x6f,0x6e,0x20,0x6c,0x6f,0x67,
  0x73,0x2f,
  
};

static const unsigned char qt_resource_name[] = {
  // config
  0x0,0x6,
  0x6,0xa6,0x4c,0xf7,
  0x0,0x63,
  0x0,0x6f,0x0,0x6e,0x0,0x66,0x0,0x69,0x0,0x67,
    // settings.conf
  0x0,0xd,
  0xd,0xf4,0x7,0x26,
  0x0,0x73,
  0x0,0x65,0x0,0x74,0x0,0x74,0x0,0x69,0x0,0x6e,0x0,0x67,0x0,0x73,0x0,0x2e,0x0,0x63,0x0,0x6f,0x0,0x6e,0x0,0x66,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
  // :/config
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
  // :/config/config
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x3,
  // :/config/config/settings.conf
  0x0,0x0,0x0,0x12,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,

};

QT_BEGIN_NAMESPACE

extern Q_CORE_EXPORT bool qRegisterResourceData
    (int, const unsigned char *, const unsigned char *, const unsigned char *);

extern Q_CORE_EXPORT bool qUnregisterResourceData
    (int, const unsigned char *, const unsigned char *, const unsigned char *);

QT_END_NAMESPACE


int QT_MANGLE_NAMESPACE(qInitResources_resource)()
{
    QT_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x01, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_resource))

int QT_MANGLE_NAMESPACE(qCleanupResources_resource)()
{
    QT_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x01, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

Q_DESTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qCleanupResources_resource))
