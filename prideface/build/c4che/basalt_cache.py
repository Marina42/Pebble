AR = 'arm-none-eabi-ar'
ARFLAGS = 'rcs'
AS = 'arm-none-eabi-gcc'
BINDIR = '/usr/local/bin'
BLOCK_MESSAGE_KEYS = []
BUILD_DIR = 'basalt'
BUILD_TYPE = 'app'
BUNDLE_BIN_DIR = 'basalt'
BUNDLE_NAME = 'prideface.pbw'
CC = ['arm-none-eabi-gcc']
CCLNK_SRC_F = []
CCLNK_TGT_F = ['-o']
CC_NAME = 'gcc'
CC_SRC_F = []
CC_TGT_F = ['-c', '-o']
CC_VERSION = ('4', '7', '2')
CFLAGS = ['-std=c99', '-mcpu=cortex-m3', '-mthumb', '-ffunction-sections', '-fdata-sections', '-g', '-fPIE', '-Os', '-D_TIME_H_', '-Wall', '-Wextra', '-Werror', '-Wno-unused-parameter', '-Wno-error=unused-function', '-Wno-error=unused-variable']
CFLAGS_MACBUNDLE = ['-fPIC']
CFLAGS_cshlib = ['-fPIC']
CPPPATH_ST = '-I%s'
DEFINES = ['RELEASE', 'PBL_PLATFORM_BASALT', 'PBL_COLOR', 'PBL_RECT', 'PBL_MICROPHONE', 'PBL_SMARTSTRAP', 'PBL_HEALTH', 'PBL_SDK_3']
DEFINES_ST = '-D%s'
DEST_BINFMT = 'elf'
DEST_CPU = 'arm'
DEST_OS = 'darwin'
INCLUDES = ['basalt']
LD = 'arm-none-eabi-ld'
LIBDIR = '/usr/local/lib'
LIBPATH_ST = '-L%s'
LIB_DIR = 'node_modules'
LIB_ST = '-l%s'
LINKFLAGS = ['-mcpu=cortex-m3', '-mthumb', '-Wl,--gc-sections', '-Wl,--warn-common', '-fPIE', '-Os']
LINKFLAGS_MACBUNDLE = ['-bundle', '-undefined', 'dynamic_lookup']
LINKFLAGS_cshlib = ['-shared']
LINKFLAGS_cstlib = ['-Wl,-Bstatic']
LINK_CC = ['arm-none-eabi-gcc']
MESSAGE_KEYS = {u'KIEZELPAY_PURCHASE_STATUS': 119526521, u'KIEZELPAY_READY': 119526512, u'KIEZELPAY_APP_ID': 119526514, u'KIEZELPAY_PURCHASE_CODE': 119526519, u'KIEZELPAY_RANDOM': 119526522, u'KIEZELPAY_INTERNET_FAIL': 119526520, u'KIEZELPAY_STATUS_TRIAL_DURATION': 119526518, u'KIEZELPAY_STATUS_CHECK': 119526513, u'KIEZELPAY_STATUS_VALIDITY_PERIOD': 119526523, u'KIEZELPAY_STATUS_CHECKSUM': 119526517, u'KIEZELPAY_STATUS_RESULT': 119526516, u'KIEZELPAY_DEVICE_TOKEN': 119526515}
MESSAGE_KEYS_DEFINITION = '/Users/marina/Desktop/Pebble/prideface/build/src/message_keys.auto.c'
MESSAGE_KEYS_HEADER = '/Users/marina/Desktop/Pebble/prideface/build/include/message_keys.auto.h'
MESSAGE_KEYS_JSON = '/Users/marina/Desktop/Pebble/prideface/build/js/message_keys.json'
PEBBLE_SDK_COMMON = '/Users/marina/Library/Application Support/Pebble SDK/SDKs/current/sdk-core/pebble/common'
PEBBLE_SDK_PLATFORM = '/Users/marina/Library/Application Support/Pebble SDK/SDKs/current/sdk-core/pebble/basalt'
PEBBLE_SDK_ROOT = '/Users/marina/Library/Application Support/Pebble SDK/SDKs/current/sdk-core/pebble'
PLATFORM = {'TAGS': ['basalt', 'color', 'rect'], 'ADDITIONAL_TEXT_LINES_FOR_PEBBLE_H': [], 'MAX_APP_BINARY_SIZE': 65536, 'MAX_RESOURCES_SIZE': 1048576, 'MAX_APP_MEMORY_SIZE': 65536, 'MAX_WORKER_MEMORY_SIZE': 10240, 'NAME': 'basalt', 'BUNDLE_BIN_DIR': 'basalt', 'BUILD_DIR': 'basalt', 'MAX_RESOURCES_SIZE_APPSTORE': 262144, 'DEFINES': ['PBL_PLATFORM_BASALT', 'PBL_COLOR', 'PBL_RECT', 'PBL_MICROPHONE', 'PBL_SMARTSTRAP', 'PBL_HEALTH']}
PLATFORM_NAME = 'basalt'
PREFIX = '/usr/local'
PROJECT_INFO = {'appKeys': {u'KIEZELPAY_PURCHASE_STATUS': 119526521, u'KIEZELPAY_READY': 119526512, u'KIEZELPAY_APP_ID': 119526514, u'KIEZELPAY_PURCHASE_CODE': 119526519, u'KIEZELPAY_RANDOM': 119526522, u'KIEZELPAY_INTERNET_FAIL': 119526520, u'KIEZELPAY_STATUS_TRIAL_DURATION': 119526518, u'KIEZELPAY_STATUS_CHECK': 119526513, u'KIEZELPAY_STATUS_VALIDITY_PERIOD': 119526523, u'KIEZELPAY_STATUS_CHECKSUM': 119526517, u'KIEZELPAY_STATUS_RESULT': 119526516, u'KIEZELPAY_DEVICE_TOKEN': 119526515}, u'sdkVersion': u'3', u'projectType': u'native', u'uuid': u'0884e36f-84a2-4618-bfac-92bbfadd836f', u'messageKeys': {u'KIEZELPAY_PURCHASE_STATUS': 119526521, u'KIEZELPAY_READY': 119526512, u'KIEZELPAY_APP_ID': 119526514, u'KIEZELPAY_PURCHASE_CODE': 119526519, u'KIEZELPAY_RANDOM': 119526522, u'KIEZELPAY_INTERNET_FAIL': 119526520, u'KIEZELPAY_STATUS_TRIAL_DURATION': 119526518, u'KIEZELPAY_STATUS_CHECK': 119526513, u'KIEZELPAY_STATUS_VALIDITY_PERIOD': 119526523, u'KIEZELPAY_STATUS_CHECKSUM': 119526517, u'KIEZELPAY_STATUS_RESULT': 119526516, u'KIEZELPAY_DEVICE_TOKEN': 119526515}, 'companyName': u'marina.sauca@gmail.com', u'enableMultiJS': False, u'watchapp': {u'onlyShownOnCommunication': False, u'hiddenApp': False, u'watchface': True}, u'capabilities': [u'configurable'], 'versionLabel': u'2.0', u'targetPlatforms': [u'basalt', u'chalk'], 'longName': u'PrideFace', u'displayName': u'PrideFace', 'shortName': u'PrideFace', u'resources': {u'media': [{u'menuIcon': True, u'type': u'bitmap', u'name': u'MENU_IMG', u'file': u'images/menu_img.png'}, {u'type': u'bitmap', u'name': u'BATTERY_82', u'file': u'images/battery_82.png'}, {u'type': u'bitmap', u'name': u'BATTERY_64', u'file': u'images/battery_64.png'}, {u'type': u'bitmap', u'name': u'BATTERY_48', u'file': u'images/battery_48.png'}, {u'type': u'bitmap', u'name': u'BATTERY_32', u'file': u'images/battery_32.png'}, {u'type': u'bitmap', u'name': u'BATTERY_16', u'file': u'images/battery_16.png'}, {u'type': u'bitmap', u'name': u'BT_DISCONNECT', u'file': u'images/no_bt.png'}, {u'type': u'bitmap', u'name': u'BATTERY_CHARGING', u'file': u'images/battery_charging.png'}, {u'type': u'bitmap', u'name': u'BATTERY_100', u'file': u'images/battery_100.png'}, {u'type': u'bitmap', u'name': u'HEART_FULL_IMG', u'file': u'images/full_heart.png'}, {u'type': u'bitmap', u'name': u'BATTERY_5', u'file': u'images/battery_5.png'}, {u'characterRegex': u'[0-9:\\-]', u'type': u'font', u'name': u'DATE_FONT_20', u'file': u'fonts/Pacifico.ttf'}, {u'characterRegex': u'[0-9:.]', u'type': u'font', u'name': u'HOUR_FONT_48', u'file': u'fonts/Pacifico.ttf'}, {u'type': u'bitmap', u'name': u'BACKGROUND_IMG', u'file': u'images/PrideFaceBackground.png'}, {u'characterRegex': u'[\\0-9%C~dca-z]', u'type': u'font', u'name': u'FONT_SMALL_17', u'file': u'fonts/DancingScript-Regular.ttf'}, {u'characterRegex': u'[0-9:.]', u'type': u'font', u'name': u'FONT_BIG_34', u'file': u'fonts/DancingScript-Bold.ttf'}]}, 'name': u'PrideFace'}
REQUESTED_PLATFORMS = [u'basalt', u'chalk']
RESOURCES_JSON = [{u'menuIcon': True, u'type': u'bitmap', u'name': u'MENU_IMG', u'file': u'images/menu_img.png'}, {u'type': u'bitmap', u'name': u'BATTERY_82', u'file': u'images/battery_82.png'}, {u'type': u'bitmap', u'name': u'BATTERY_64', u'file': u'images/battery_64.png'}, {u'type': u'bitmap', u'name': u'BATTERY_48', u'file': u'images/battery_48.png'}, {u'type': u'bitmap', u'name': u'BATTERY_32', u'file': u'images/battery_32.png'}, {u'type': u'bitmap', u'name': u'BATTERY_16', u'file': u'images/battery_16.png'}, {u'type': u'bitmap', u'name': u'BT_DISCONNECT', u'file': u'images/no_bt.png'}, {u'type': u'bitmap', u'name': u'BATTERY_CHARGING', u'file': u'images/battery_charging.png'}, {u'type': u'bitmap', u'name': u'BATTERY_100', u'file': u'images/battery_100.png'}, {u'type': u'bitmap', u'name': u'HEART_FULL_IMG', u'file': u'images/full_heart.png'}, {u'type': u'bitmap', u'name': u'BATTERY_5', u'file': u'images/battery_5.png'}, {u'characterRegex': u'[0-9:\\-]', u'type': u'font', u'name': u'DATE_FONT_20', u'file': u'fonts/Pacifico.ttf'}, {u'characterRegex': u'[0-9:.]', u'type': u'font', u'name': u'HOUR_FONT_48', u'file': u'fonts/Pacifico.ttf'}, {u'type': u'bitmap', u'name': u'BACKGROUND_IMG', u'file': u'images/PrideFaceBackground.png'}, {u'characterRegex': u'[\\0-9%C~dca-z]', u'type': u'font', u'name': u'FONT_SMALL_17', u'file': u'fonts/DancingScript-Regular.ttf'}, {u'characterRegex': u'[0-9:.]', u'type': u'font', u'name': u'FONT_BIG_34', u'file': u'fonts/DancingScript-Bold.ttf'}]
RPATH_ST = '-Wl,-rpath,%s'
SDK_VERSION_MAJOR = 5
SDK_VERSION_MINOR = 78
SHLIB_MARKER = None
SIZE = 'arm-none-eabi-size'
SONAME_ST = '-Wl,-h,%s'
STLIBPATH_ST = '-L%s'
STLIB_MARKER = None
STLIB_ST = '-l%s'
SUPPORTED_PLATFORMS = ['aplite', 'basalt', 'chalk']
TARGET_PLATFORMS = ['chalk', 'basalt']
TIMESTAMP = 1466672683
cprogram_PATTERN = '%s'
cshlib_PATTERN = 'lib%s.so'
cstlib_PATTERN = 'lib%s.a'
macbundle_PATTERN = '%s.bundle'
