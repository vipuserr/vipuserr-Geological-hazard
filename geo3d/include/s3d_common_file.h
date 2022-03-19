#ifndef _GM_COMMON_FILE_H_
#define _GM_COMMON_FILE_H_



namespace Smart3dMap
{

	//
	// platform dependent
	//
#ifdef LINUX26
	typedef long long interior_index;
	typedef unsigned char unsigned char;
#else

	typedef __int64 interior_index;

#define AUTO_ALLOC_MEMORY(size) (unsigned char*)::CoTaskMemAlloc( size );
#define AUTO_FREE_MEMORY(p) { if(p){ ::CoTaskMemFree(p); (p)=NULL;} }
#define AUTO_ALIGNED_ALLOC_MEMORY(size, alignment) (unsigned char*)_aligned_malloc( size, alignment );
#define AUTO_ALIGNED_FREE_MEMORY(p) { if(p){ _aligned_free(p); (p)=NULL;} }
#define AUTO_CLOSE_HANDLE( handle ) if ( handle ) { CloseHandle( handle); handle = 0 ; }
#define AUTO_RELEASE(ptr) {if(ptr){(ptr)->Release();(ptr)=NULL;} }
#define AUTO_RELEASE_OUT_RES(v) if(v){((IDispatch*)v)->Release();}
#define	AUTO_RELEASE_SHARED_DATA(ptr) {if(ptr){(ptr)->release();(ptr)=NULL;} }
#define SE_STD_CALL __stdcall
	typedef unsigned long ulong;
	typedef unsigned int uint;
	typedef unsigned short ushort;

#endif //LINUX26

	//
	// internationalization
	//
#ifdef _UNICODE
	typedef std::wstring ustring;
	typedef wchar_t* pstr;
	typedef const wchar_t* cpstr;
#define _gstr(x) L##x

#define SE_STRING_LOWER(str) std::transform( str.begin(), str.end(), str.begin(), ::towlower );
#define SE_STRING_UPPER(str) std::transform( str.begin(), str.end(), str.begin(), ::towupper );

#else
	typedef std::string ustring;
	typedef char* pstr;
	typedef const char* cpstr;
#define _gstr(x) x

#define SE_STRING_LOWER(str) std::transform( str.begin(), str.end(), str.begin(), ::tolower );
#define SE_STRING_UPPER(str) std::transform( str.begin(), str.end(), str.begin(), ::toupper );

#endif // _UNICODE

typedef unsigned long dword;
typedef double time_value;

// #ifndef USE_SYS_BYTE
// typedef unsigned char unsigned char;
// #endif 

#ifdef _DEBUG
#define SE_TRACE0(format) { wchar_t str[1024]; swprintf( str, format ); OutputDebugString(str);}
#define SE_TRACE1(format, val1) { wchar_t str[1024]; swprintf( str, format, val1 ); OutputDebugString(str);}
#define SE_TRACE2(format, val1, val2) { wchar_t str[1024]; swprintf( str, format, val1, val2 ); OutputDebugString(str);}
#define SE_TRACE3(format, val1, val2, val3) { wchar_t str[1024]; swprintf( str, format, val1, val2, val3 ); OutputDebugString(str);}
#else
#define SE_TRACE0(format)
#define SE_TRACE1(format, val1) 
#define SE_TRACE2(format, val1, val2) 
#define SE_TRACE3(format, val1, val2, val3) 
#endif //_DEBUG

const size_t MAX_FILE_PATH = 1024;

#define MIN(a,b) ( (a)<(b) ? (a):(b))
#define MAX(a,b) ( (a)>(b) ? (a):(b))

#define AUTO_DELETE(ptr) {if(ptr){delete ptr;(ptr)=NULL;} }
#define AUTO_DELETE_ARRAY(ptr) {if(ptr){delete[] ptr;(ptr)=NULL;} }
#define AUTO_FREE(ptr) {if(ptr){free(ptr);(ptr)=NULL;} }

#define CLAMP( in_value, min_value, max_value ) (MIN( max_value, MAX(in_value, min_value)))

//const double PIF = 3.1415926535897932384626433832795;
#ifndef PI
	#define PI 	3.1415926535897932384626433832795
#endif

const double DOUBLE_PI = 6.283185307179586476925286766559;

const double HALF_PI = 1.5707963267948966192313216916398;

const double DEGREE = 57.295779513082320876798154814105;

const double RADIAN = 0.017453292519943295769236907684886;

const double MIN_TIME_INTERVAL = 0.01;

#define FAST_ULONG_F(f)	(*(ulong*)&(f))

#define FAST_SIGN_F(f)	((*(ulong*)&(f))&0x80000000)

#define FAST_SIGN_I(f)	((f)&0x80000000)


// rank
#define SYSTEM_RANK_MASK 0x00ffffff
#define OBSERVER_RANK_MASK 0xff0000ff
#define INSERT_SYSTEM_RANK( rank, val ) {	rank &= SYSTEM_RANK_MASK; \
											rank|= (ulong)(val)<<24;\
										}
#define INSERT_OBSERVER_RANK( rank, val ) {	if ( val < 0.0 ) val = 0.0f;\
											if ( val > 1.0 ) val = 1.0f;\
											rank &= OBSERVER_RANK_MASK;\
											ulong obs_rank = (ulong)(val * 65535 )<<8;\
											rank |= obs_rank;\
											}

#define NORMALIZE_RADIAN( rad ) {   if ( rad > DOUBLE_PI )\
										rad -= gmMath<double>::floor_( gmMath<double>::fabs_(rad) / DOUBLE_PI ) * DOUBLE_PI;\
									else if ( rad < DOUBLE_PI )\
										rad += gmMath<double>::floor_( gmMath<double>::fabs_(rad) / DOUBLE_PI ) * DOUBLE_PI;\
								}

typedef std::pair< interior_index, interior_index > gm_guid_pair;

#define SE_GUID_TO_PAIR( gu_id, guid_key ) {	guid_key.first = (__int64)((ulong *) &gu_id)[0]<<32 | ((ulong *) &gu_id)[1]; \
												guid_key.second = (__int64)((ulong *) &gu_id)[2]<<32 | ((ulong *) &gu_id)[3];}

#define SE_GUID_FROM_PAIR( gu_id, guid_key ) {	((ulong *) &gu_id)[0] = (guid_key.first >> 32) & 0x00000000ffffffff;\
												((ulong *) &gu_id)[1] = guid_key.first & 0x00000000ffffffff;\
												((ulong *) &gu_id)[2] = (guid_key.second >> 32) & 0x00000000ffffffff;\
												((ulong *) &gu_id)[3] = guid_key.second & 0x00000000ffffffff;}

#define GUID_TO_INT64( gu_id, part1, part2 ) {	part1 = (__int64)((ulong *) &gu_id)[0]<<32 | ((ulong *) &gu_id)[1]; \
												part2 = (__int64)((ulong *) &gu_id)[2]<<32 | ((ulong *) &gu_id)[3];}


#define GUID_FROM_INT64( gu_id, part1, part2 ) {((ulong *) &gu_id)[0] = (part1 >> 32) & 0x00000000ffffffff;\
												((ulong *) &gu_id)[1] = part1 & 0x00000000ffffffff;\
												((ulong *) &gu_id)[2] = (part2 >> 32) & 0x00000000ffffffff;\
												((ulong *) &gu_id)[3] = part2 & 0x00000000ffffffff;}
}

#endif