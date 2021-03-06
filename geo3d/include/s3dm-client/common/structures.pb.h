// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: common/structures.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_common_2fstructures_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_common_2fstructures_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3015000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3015008 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_common_2fstructures_2eproto LIBS3DMGRPC_API
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct LIBS3DMGRPC_API TableStruct_common_2fstructures_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern LIBS3DMGRPC_API const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_common_2fstructures_2eproto;
LIBS3DMGRPC_API ::PROTOBUF_NAMESPACE_ID::Metadata descriptor_table_common_2fstructures_2eproto_metadata_getter(int index);
namespace smart3dmap {
namespace v1 {
class G2dDot;
struct G2dDotDefaultTypeInternal;
LIBS3DMGRPC_API extern G2dDotDefaultTypeInternal _G2dDot_default_instance_;
class Rect2D;
struct Rect2DDefaultTypeInternal;
LIBS3DMGRPC_API extern Rect2DDefaultTypeInternal _Rect2D_default_instance_;
class Rect3D;
struct Rect3DDefaultTypeInternal;
LIBS3DMGRPC_API extern Rect3DDefaultTypeInternal _Rect3D_default_instance_;
}  // namespace v1
}  // namespace smart3dmap
PROTOBUF_NAMESPACE_OPEN
template<> LIBS3DMGRPC_API ::smart3dmap::v1::G2dDot* Arena::CreateMaybeMessage<::smart3dmap::v1::G2dDot>(Arena*);
template<> LIBS3DMGRPC_API ::smart3dmap::v1::Rect2D* Arena::CreateMaybeMessage<::smart3dmap::v1::Rect2D>(Arena*);
template<> LIBS3DMGRPC_API ::smart3dmap::v1::Rect3D* Arena::CreateMaybeMessage<::smart3dmap::v1::Rect3D>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace smart3dmap {
namespace v1 {

// ===================================================================

class LIBS3DMGRPC_API Rect2D PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:smart3dmap.v1.Rect2D) */ {
 public:
  inline Rect2D() : Rect2D(nullptr) {}
  virtual ~Rect2D();
  explicit constexpr Rect2D(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Rect2D(const Rect2D& from);
  Rect2D(Rect2D&& from) noexcept
    : Rect2D() {
    *this = ::std::move(from);
  }

  inline Rect2D& operator=(const Rect2D& from) {
    CopyFrom(from);
    return *this;
  }
  inline Rect2D& operator=(Rect2D&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Rect2D& default_instance() {
    return *internal_default_instance();
  }
  static inline const Rect2D* internal_default_instance() {
    return reinterpret_cast<const Rect2D*>(
               &_Rect2D_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Rect2D& a, Rect2D& b) {
    a.Swap(&b);
  }
  inline void Swap(Rect2D* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Rect2D* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Rect2D* New() const final {
    return CreateMaybeMessage<Rect2D>(nullptr);
  }

  Rect2D* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Rect2D>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Rect2D& from);
  void MergeFrom(const Rect2D& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Rect2D* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "smart3dmap.v1.Rect2D";
  }
  protected:
  explicit Rect2D(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    return ::descriptor_table_common_2fstructures_2eproto_metadata_getter(kIndexInFileMessages);
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMinXFieldNumber = 1,
    kMaxXFieldNumber = 2,
    kMinYFieldNumber = 3,
    kMaxYFieldNumber = 4,
  };
  // double min_x = 1;
  void clear_min_x();
  double min_x() const;
  void set_min_x(double value);
  private:
  double _internal_min_x() const;
  void _internal_set_min_x(double value);
  public:

  // double max_x = 2;
  void clear_max_x();
  double max_x() const;
  void set_max_x(double value);
  private:
  double _internal_max_x() const;
  void _internal_set_max_x(double value);
  public:

  // double min_y = 3;
  void clear_min_y();
  double min_y() const;
  void set_min_y(double value);
  private:
  double _internal_min_y() const;
  void _internal_set_min_y(double value);
  public:

  // double max_y = 4;
  void clear_max_y();
  double max_y() const;
  void set_max_y(double value);
  private:
  double _internal_max_y() const;
  void _internal_set_max_y(double value);
  public:

  // @@protoc_insertion_point(class_scope:smart3dmap.v1.Rect2D)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  double min_x_;
  double max_x_;
  double min_y_;
  double max_y_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_common_2fstructures_2eproto;
};
// -------------------------------------------------------------------

class LIBS3DMGRPC_API Rect3D PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:smart3dmap.v1.Rect3D) */ {
 public:
  inline Rect3D() : Rect3D(nullptr) {}
  virtual ~Rect3D();
  explicit constexpr Rect3D(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Rect3D(const Rect3D& from);
  Rect3D(Rect3D&& from) noexcept
    : Rect3D() {
    *this = ::std::move(from);
  }

  inline Rect3D& operator=(const Rect3D& from) {
    CopyFrom(from);
    return *this;
  }
  inline Rect3D& operator=(Rect3D&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Rect3D& default_instance() {
    return *internal_default_instance();
  }
  static inline const Rect3D* internal_default_instance() {
    return reinterpret_cast<const Rect3D*>(
               &_Rect3D_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Rect3D& a, Rect3D& b) {
    a.Swap(&b);
  }
  inline void Swap(Rect3D* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Rect3D* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Rect3D* New() const final {
    return CreateMaybeMessage<Rect3D>(nullptr);
  }

  Rect3D* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Rect3D>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Rect3D& from);
  void MergeFrom(const Rect3D& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Rect3D* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "smart3dmap.v1.Rect3D";
  }
  protected:
  explicit Rect3D(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    return ::descriptor_table_common_2fstructures_2eproto_metadata_getter(kIndexInFileMessages);
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMinXFieldNumber = 1,
    kMaxXFieldNumber = 2,
    kMinYFieldNumber = 3,
    kMax4FieldNumber = 4,
    kMinZFieldNumber = 5,
    kMaxZFieldNumber = 6,
  };
  // double min_x = 1;
  void clear_min_x();
  double min_x() const;
  void set_min_x(double value);
  private:
  double _internal_min_x() const;
  void _internal_set_min_x(double value);
  public:

  // double max_x = 2;
  void clear_max_x();
  double max_x() const;
  void set_max_x(double value);
  private:
  double _internal_max_x() const;
  void _internal_set_max_x(double value);
  public:

  // double min_y = 3;
  void clear_min_y();
  double min_y() const;
  void set_min_y(double value);
  private:
  double _internal_min_y() const;
  void _internal_set_min_y(double value);
  public:

  // double max_4 = 4;
  void clear_max_4();
  double max_4() const;
  void set_max_4(double value);
  private:
  double _internal_max_4() const;
  void _internal_set_max_4(double value);
  public:

  // double min_z = 5;
  void clear_min_z();
  double min_z() const;
  void set_min_z(double value);
  private:
  double _internal_min_z() const;
  void _internal_set_min_z(double value);
  public:

  // double max_z = 6;
  void clear_max_z();
  double max_z() const;
  void set_max_z(double value);
  private:
  double _internal_max_z() const;
  void _internal_set_max_z(double value);
  public:

  // @@protoc_insertion_point(class_scope:smart3dmap.v1.Rect3D)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  double min_x_;
  double max_x_;
  double min_y_;
  double max_4_;
  double min_z_;
  double max_z_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_common_2fstructures_2eproto;
};
// -------------------------------------------------------------------

class LIBS3DMGRPC_API G2dDot PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:smart3dmap.v1.G2dDot) */ {
 public:
  inline G2dDot() : G2dDot(nullptr) {}
  virtual ~G2dDot();
  explicit constexpr G2dDot(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  G2dDot(const G2dDot& from);
  G2dDot(G2dDot&& from) noexcept
    : G2dDot() {
    *this = ::std::move(from);
  }

  inline G2dDot& operator=(const G2dDot& from) {
    CopyFrom(from);
    return *this;
  }
  inline G2dDot& operator=(G2dDot&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const G2dDot& default_instance() {
    return *internal_default_instance();
  }
  static inline const G2dDot* internal_default_instance() {
    return reinterpret_cast<const G2dDot*>(
               &_G2dDot_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(G2dDot& a, G2dDot& b) {
    a.Swap(&b);
  }
  inline void Swap(G2dDot* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(G2dDot* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline G2dDot* New() const final {
    return CreateMaybeMessage<G2dDot>(nullptr);
  }

  G2dDot* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<G2dDot>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const G2dDot& from);
  void MergeFrom(const G2dDot& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(G2dDot* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "smart3dmap.v1.G2dDot";
  }
  protected:
  explicit G2dDot(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    return ::descriptor_table_common_2fstructures_2eproto_metadata_getter(kIndexInFileMessages);
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kXFieldNumber = 1,
    kYFieldNumber = 2,
  };
  // double x = 1;
  void clear_x();
  double x() const;
  void set_x(double value);
  private:
  double _internal_x() const;
  void _internal_set_x(double value);
  public:

  // double y = 2;
  void clear_y();
  double y() const;
  void set_y(double value);
  private:
  double _internal_y() const;
  void _internal_set_y(double value);
  public:

  // @@protoc_insertion_point(class_scope:smart3dmap.v1.G2dDot)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  double x_;
  double y_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_common_2fstructures_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Rect2D

// double min_x = 1;
inline void Rect2D::clear_min_x() {
  min_x_ = 0;
}
inline double Rect2D::_internal_min_x() const {
  return min_x_;
}
inline double Rect2D::min_x() const {
  // @@protoc_insertion_point(field_get:smart3dmap.v1.Rect2D.min_x)
  return _internal_min_x();
}
inline void Rect2D::_internal_set_min_x(double value) {
  
  min_x_ = value;
}
inline void Rect2D::set_min_x(double value) {
  _internal_set_min_x(value);
  // @@protoc_insertion_point(field_set:smart3dmap.v1.Rect2D.min_x)
}

// double max_x = 2;
inline void Rect2D::clear_max_x() {
  max_x_ = 0;
}
inline double Rect2D::_internal_max_x() const {
  return max_x_;
}
inline double Rect2D::max_x() const {
  // @@protoc_insertion_point(field_get:smart3dmap.v1.Rect2D.max_x)
  return _internal_max_x();
}
inline void Rect2D::_internal_set_max_x(double value) {
  
  max_x_ = value;
}
inline void Rect2D::set_max_x(double value) {
  _internal_set_max_x(value);
  // @@protoc_insertion_point(field_set:smart3dmap.v1.Rect2D.max_x)
}

// double min_y = 3;
inline void Rect2D::clear_min_y() {
  min_y_ = 0;
}
inline double Rect2D::_internal_min_y() const {
  return min_y_;
}
inline double Rect2D::min_y() const {
  // @@protoc_insertion_point(field_get:smart3dmap.v1.Rect2D.min_y)
  return _internal_min_y();
}
inline void Rect2D::_internal_set_min_y(double value) {
  
  min_y_ = value;
}
inline void Rect2D::set_min_y(double value) {
  _internal_set_min_y(value);
  // @@protoc_insertion_point(field_set:smart3dmap.v1.Rect2D.min_y)
}

// double max_y = 4;
inline void Rect2D::clear_max_y() {
  max_y_ = 0;
}
inline double Rect2D::_internal_max_y() const {
  return max_y_;
}
inline double Rect2D::max_y() const {
  // @@protoc_insertion_point(field_get:smart3dmap.v1.Rect2D.max_y)
  return _internal_max_y();
}
inline void Rect2D::_internal_set_max_y(double value) {
  
  max_y_ = value;
}
inline void Rect2D::set_max_y(double value) {
  _internal_set_max_y(value);
  // @@protoc_insertion_point(field_set:smart3dmap.v1.Rect2D.max_y)
}

// -------------------------------------------------------------------

// Rect3D

// double min_x = 1;
inline void Rect3D::clear_min_x() {
  min_x_ = 0;
}
inline double Rect3D::_internal_min_x() const {
  return min_x_;
}
inline double Rect3D::min_x() const {
  // @@protoc_insertion_point(field_get:smart3dmap.v1.Rect3D.min_x)
  return _internal_min_x();
}
inline void Rect3D::_internal_set_min_x(double value) {
  
  min_x_ = value;
}
inline void Rect3D::set_min_x(double value) {
  _internal_set_min_x(value);
  // @@protoc_insertion_point(field_set:smart3dmap.v1.Rect3D.min_x)
}

// double max_x = 2;
inline void Rect3D::clear_max_x() {
  max_x_ = 0;
}
inline double Rect3D::_internal_max_x() const {
  return max_x_;
}
inline double Rect3D::max_x() const {
  // @@protoc_insertion_point(field_get:smart3dmap.v1.Rect3D.max_x)
  return _internal_max_x();
}
inline void Rect3D::_internal_set_max_x(double value) {
  
  max_x_ = value;
}
inline void Rect3D::set_max_x(double value) {
  _internal_set_max_x(value);
  // @@protoc_insertion_point(field_set:smart3dmap.v1.Rect3D.max_x)
}

// double min_y = 3;
inline void Rect3D::clear_min_y() {
  min_y_ = 0;
}
inline double Rect3D::_internal_min_y() const {
  return min_y_;
}
inline double Rect3D::min_y() const {
  // @@protoc_insertion_point(field_get:smart3dmap.v1.Rect3D.min_y)
  return _internal_min_y();
}
inline void Rect3D::_internal_set_min_y(double value) {
  
  min_y_ = value;
}
inline void Rect3D::set_min_y(double value) {
  _internal_set_min_y(value);
  // @@protoc_insertion_point(field_set:smart3dmap.v1.Rect3D.min_y)
}

// double max_4 = 4;
inline void Rect3D::clear_max_4() {
  max_4_ = 0;
}
inline double Rect3D::_internal_max_4() const {
  return max_4_;
}
inline double Rect3D::max_4() const {
  // @@protoc_insertion_point(field_get:smart3dmap.v1.Rect3D.max_4)
  return _internal_max_4();
}
inline void Rect3D::_internal_set_max_4(double value) {
  
  max_4_ = value;
}
inline void Rect3D::set_max_4(double value) {
  _internal_set_max_4(value);
  // @@protoc_insertion_point(field_set:smart3dmap.v1.Rect3D.max_4)
}

// double min_z = 5;
inline void Rect3D::clear_min_z() {
  min_z_ = 0;
}
inline double Rect3D::_internal_min_z() const {
  return min_z_;
}
inline double Rect3D::min_z() const {
  // @@protoc_insertion_point(field_get:smart3dmap.v1.Rect3D.min_z)
  return _internal_min_z();
}
inline void Rect3D::_internal_set_min_z(double value) {
  
  min_z_ = value;
}
inline void Rect3D::set_min_z(double value) {
  _internal_set_min_z(value);
  // @@protoc_insertion_point(field_set:smart3dmap.v1.Rect3D.min_z)
}

// double max_z = 6;
inline void Rect3D::clear_max_z() {
  max_z_ = 0;
}
inline double Rect3D::_internal_max_z() const {
  return max_z_;
}
inline double Rect3D::max_z() const {
  // @@protoc_insertion_point(field_get:smart3dmap.v1.Rect3D.max_z)
  return _internal_max_z();
}
inline void Rect3D::_internal_set_max_z(double value) {
  
  max_z_ = value;
}
inline void Rect3D::set_max_z(double value) {
  _internal_set_max_z(value);
  // @@protoc_insertion_point(field_set:smart3dmap.v1.Rect3D.max_z)
}

// -------------------------------------------------------------------

// G2dDot

// double x = 1;
inline void G2dDot::clear_x() {
  x_ = 0;
}
inline double G2dDot::_internal_x() const {
  return x_;
}
inline double G2dDot::x() const {
  // @@protoc_insertion_point(field_get:smart3dmap.v1.G2dDot.x)
  return _internal_x();
}
inline void G2dDot::_internal_set_x(double value) {
  
  x_ = value;
}
inline void G2dDot::set_x(double value) {
  _internal_set_x(value);
  // @@protoc_insertion_point(field_set:smart3dmap.v1.G2dDot.x)
}

// double y = 2;
inline void G2dDot::clear_y() {
  y_ = 0;
}
inline double G2dDot::_internal_y() const {
  return y_;
}
inline double G2dDot::y() const {
  // @@protoc_insertion_point(field_get:smart3dmap.v1.G2dDot.y)
  return _internal_y();
}
inline void G2dDot::_internal_set_y(double value) {
  
  y_ = value;
}
inline void G2dDot::set_y(double value) {
  _internal_set_y(value);
  // @@protoc_insertion_point(field_set:smart3dmap.v1.G2dDot.y)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace smart3dmap

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_common_2fstructures_2eproto
