// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Trd_GetHistoryOrderFillList.proto

#ifndef PROTOBUF_Trd_5fGetHistoryOrderFillList_2eproto__INCLUDED
#define PROTOBUF_Trd_5fGetHistoryOrderFillList_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "Common.pb.h"
#include "Trd_Common.pb.h"
// @@protoc_insertion_point(includes)

namespace protobuf_Trd_5fGetHistoryOrderFillList_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[4];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsC2SImpl();
void InitDefaultsC2S();
void InitDefaultsS2CImpl();
void InitDefaultsS2C();
void InitDefaultsRequestImpl();
void InitDefaultsRequest();
void InitDefaultsResponseImpl();
void InitDefaultsResponse();
inline void InitDefaults() {
  InitDefaultsC2S();
  InitDefaultsS2C();
  InitDefaultsRequest();
  InitDefaultsResponse();
}
}  // namespace protobuf_Trd_5fGetHistoryOrderFillList_2eproto
namespace Trd_GetHistoryOrderFillList {
class C2S;
class C2SDefaultTypeInternal;
extern C2SDefaultTypeInternal _C2S_default_instance_;
class Request;
class RequestDefaultTypeInternal;
extern RequestDefaultTypeInternal _Request_default_instance_;
class Response;
class ResponseDefaultTypeInternal;
extern ResponseDefaultTypeInternal _Response_default_instance_;
class S2C;
class S2CDefaultTypeInternal;
extern S2CDefaultTypeInternal _S2C_default_instance_;
}  // namespace Trd_GetHistoryOrderFillList
namespace Trd_GetHistoryOrderFillList {

// ===================================================================

class C2S : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Trd_GetHistoryOrderFillList.C2S) */ {
 public:
  C2S();
  virtual ~C2S();

  C2S(const C2S& from);

  inline C2S& operator=(const C2S& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  C2S(C2S&& from) noexcept
    : C2S() {
    *this = ::std::move(from);
  }

  inline C2S& operator=(C2S&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const C2S& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const C2S* internal_default_instance() {
    return reinterpret_cast<const C2S*>(
               &_C2S_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(C2S* other);
  friend void swap(C2S& a, C2S& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline C2S* New() const PROTOBUF_FINAL { return New(NULL); }

  C2S* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const C2S& from);
  void MergeFrom(const C2S& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(C2S* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required .Trd_Common.TrdHeader header = 1;
  bool has_header() const;
  void clear_header();
  static const int kHeaderFieldNumber = 1;
  const ::Trd_Common::TrdHeader& header() const;
  ::Trd_Common::TrdHeader* release_header();
  ::Trd_Common::TrdHeader* mutable_header();
  void set_allocated_header(::Trd_Common::TrdHeader* header);

  // required .Trd_Common.TrdFilterConditions filterConditions = 2;
  bool has_filterconditions() const;
  void clear_filterconditions();
  static const int kFilterConditionsFieldNumber = 2;
  const ::Trd_Common::TrdFilterConditions& filterconditions() const;
  ::Trd_Common::TrdFilterConditions* release_filterconditions();
  ::Trd_Common::TrdFilterConditions* mutable_filterconditions();
  void set_allocated_filterconditions(::Trd_Common::TrdFilterConditions* filterconditions);

  // @@protoc_insertion_point(class_scope:Trd_GetHistoryOrderFillList.C2S)
 private:
  void set_has_header();
  void clear_has_header();
  void set_has_filterconditions();
  void clear_has_filterconditions();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::Trd_Common::TrdHeader* header_;
  ::Trd_Common::TrdFilterConditions* filterconditions_;
  friend struct ::protobuf_Trd_5fGetHistoryOrderFillList_2eproto::TableStruct;
  friend void ::protobuf_Trd_5fGetHistoryOrderFillList_2eproto::InitDefaultsC2SImpl();
};
// -------------------------------------------------------------------

class S2C : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Trd_GetHistoryOrderFillList.S2C) */ {
 public:
  S2C();
  virtual ~S2C();

  S2C(const S2C& from);

  inline S2C& operator=(const S2C& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  S2C(S2C&& from) noexcept
    : S2C() {
    *this = ::std::move(from);
  }

  inline S2C& operator=(S2C&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const S2C& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const S2C* internal_default_instance() {
    return reinterpret_cast<const S2C*>(
               &_S2C_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(S2C* other);
  friend void swap(S2C& a, S2C& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline S2C* New() const PROTOBUF_FINAL { return New(NULL); }

  S2C* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const S2C& from);
  void MergeFrom(const S2C& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(S2C* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .Trd_Common.OrderFill orderFillList = 2;
  int orderfilllist_size() const;
  void clear_orderfilllist();
  static const int kOrderFillListFieldNumber = 2;
  const ::Trd_Common::OrderFill& orderfilllist(int index) const;
  ::Trd_Common::OrderFill* mutable_orderfilllist(int index);
  ::Trd_Common::OrderFill* add_orderfilllist();
  ::google::protobuf::RepeatedPtrField< ::Trd_Common::OrderFill >*
      mutable_orderfilllist();
  const ::google::protobuf::RepeatedPtrField< ::Trd_Common::OrderFill >&
      orderfilllist() const;

  // required .Trd_Common.TrdHeader header = 1;
  bool has_header() const;
  void clear_header();
  static const int kHeaderFieldNumber = 1;
  const ::Trd_Common::TrdHeader& header() const;
  ::Trd_Common::TrdHeader* release_header();
  ::Trd_Common::TrdHeader* mutable_header();
  void set_allocated_header(::Trd_Common::TrdHeader* header);

  // @@protoc_insertion_point(class_scope:Trd_GetHistoryOrderFillList.S2C)
 private:
  void set_has_header();
  void clear_has_header();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::Trd_Common::OrderFill > orderfilllist_;
  ::Trd_Common::TrdHeader* header_;
  friend struct ::protobuf_Trd_5fGetHistoryOrderFillList_2eproto::TableStruct;
  friend void ::protobuf_Trd_5fGetHistoryOrderFillList_2eproto::InitDefaultsS2CImpl();
};
// -------------------------------------------------------------------

class Request : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Trd_GetHistoryOrderFillList.Request) */ {
 public:
  Request();
  virtual ~Request();

  Request(const Request& from);

  inline Request& operator=(const Request& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Request(Request&& from) noexcept
    : Request() {
    *this = ::std::move(from);
  }

  inline Request& operator=(Request&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Request& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Request* internal_default_instance() {
    return reinterpret_cast<const Request*>(
               &_Request_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(Request* other);
  friend void swap(Request& a, Request& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Request* New() const PROTOBUF_FINAL { return New(NULL); }

  Request* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Request& from);
  void MergeFrom(const Request& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(Request* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required .Trd_GetHistoryOrderFillList.C2S c2s = 1;
  bool has_c2s() const;
  void clear_c2s();
  static const int kC2SFieldNumber = 1;
  const ::Trd_GetHistoryOrderFillList::C2S& c2s() const;
  ::Trd_GetHistoryOrderFillList::C2S* release_c2s();
  ::Trd_GetHistoryOrderFillList::C2S* mutable_c2s();
  void set_allocated_c2s(::Trd_GetHistoryOrderFillList::C2S* c2s);

  // @@protoc_insertion_point(class_scope:Trd_GetHistoryOrderFillList.Request)
 private:
  void set_has_c2s();
  void clear_has_c2s();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::Trd_GetHistoryOrderFillList::C2S* c2s_;
  friend struct ::protobuf_Trd_5fGetHistoryOrderFillList_2eproto::TableStruct;
  friend void ::protobuf_Trd_5fGetHistoryOrderFillList_2eproto::InitDefaultsRequestImpl();
};
// -------------------------------------------------------------------

class Response : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Trd_GetHistoryOrderFillList.Response) */ {
 public:
  Response();
  virtual ~Response();

  Response(const Response& from);

  inline Response& operator=(const Response& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Response(Response&& from) noexcept
    : Response() {
    *this = ::std::move(from);
  }

  inline Response& operator=(Response&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Response& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Response* internal_default_instance() {
    return reinterpret_cast<const Response*>(
               &_Response_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    3;

  void Swap(Response* other);
  friend void swap(Response& a, Response& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Response* New() const PROTOBUF_FINAL { return New(NULL); }

  Response* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Response& from);
  void MergeFrom(const Response& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(Response* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string retMsg = 2;
  bool has_retmsg() const;
  void clear_retmsg();
  static const int kRetMsgFieldNumber = 2;
  const ::std::string& retmsg() const;
  void set_retmsg(const ::std::string& value);
  #if LANG_CXX11
  void set_retmsg(::std::string&& value);
  #endif
  void set_retmsg(const char* value);
  void set_retmsg(const char* value, size_t size);
  ::std::string* mutable_retmsg();
  ::std::string* release_retmsg();
  void set_allocated_retmsg(::std::string* retmsg);

  // optional .Trd_GetHistoryOrderFillList.S2C s2c = 4;
  bool has_s2c() const;
  void clear_s2c();
  static const int kS2CFieldNumber = 4;
  const ::Trd_GetHistoryOrderFillList::S2C& s2c() const;
  ::Trd_GetHistoryOrderFillList::S2C* release_s2c();
  ::Trd_GetHistoryOrderFillList::S2C* mutable_s2c();
  void set_allocated_s2c(::Trd_GetHistoryOrderFillList::S2C* s2c);

  // optional int32 errCode = 3;
  bool has_errcode() const;
  void clear_errcode();
  static const int kErrCodeFieldNumber = 3;
  ::google::protobuf::int32 errcode() const;
  void set_errcode(::google::protobuf::int32 value);

  // required int32 retType = 1 [default = -400];
  bool has_rettype() const;
  void clear_rettype();
  static const int kRetTypeFieldNumber = 1;
  ::google::protobuf::int32 rettype() const;
  void set_rettype(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:Trd_GetHistoryOrderFillList.Response)
 private:
  void set_has_rettype();
  void clear_has_rettype();
  void set_has_retmsg();
  void clear_has_retmsg();
  void set_has_errcode();
  void clear_has_errcode();
  void set_has_s2c();
  void clear_has_s2c();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr retmsg_;
  ::Trd_GetHistoryOrderFillList::S2C* s2c_;
  ::google::protobuf::int32 errcode_;
  ::google::protobuf::int32 rettype_;
  friend struct ::protobuf_Trd_5fGetHistoryOrderFillList_2eproto::TableStruct;
  friend void ::protobuf_Trd_5fGetHistoryOrderFillList_2eproto::InitDefaultsResponseImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// C2S

// required .Trd_Common.TrdHeader header = 1;
inline bool C2S::has_header() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void C2S::set_has_header() {
  _has_bits_[0] |= 0x00000001u;
}
inline void C2S::clear_has_header() {
  _has_bits_[0] &= ~0x00000001u;
}
inline const ::Trd_Common::TrdHeader& C2S::header() const {
  const ::Trd_Common::TrdHeader* p = header_;
  // @@protoc_insertion_point(field_get:Trd_GetHistoryOrderFillList.C2S.header)
  return p != NULL ? *p : *reinterpret_cast<const ::Trd_Common::TrdHeader*>(
      &::Trd_Common::_TrdHeader_default_instance_);
}
inline ::Trd_Common::TrdHeader* C2S::release_header() {
  // @@protoc_insertion_point(field_release:Trd_GetHistoryOrderFillList.C2S.header)
  clear_has_header();
  ::Trd_Common::TrdHeader* temp = header_;
  header_ = NULL;
  return temp;
}
inline ::Trd_Common::TrdHeader* C2S::mutable_header() {
  set_has_header();
  if (header_ == NULL) {
    header_ = new ::Trd_Common::TrdHeader;
  }
  // @@protoc_insertion_point(field_mutable:Trd_GetHistoryOrderFillList.C2S.header)
  return header_;
}
inline void C2S::set_allocated_header(::Trd_Common::TrdHeader* header) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete reinterpret_cast< ::google::protobuf::MessageLite*>(header_);
  }
  if (header) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      header = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, header, submessage_arena);
    }
    set_has_header();
  } else {
    clear_has_header();
  }
  header_ = header;
  // @@protoc_insertion_point(field_set_allocated:Trd_GetHistoryOrderFillList.C2S.header)
}

// required .Trd_Common.TrdFilterConditions filterConditions = 2;
inline bool C2S::has_filterconditions() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void C2S::set_has_filterconditions() {
  _has_bits_[0] |= 0x00000002u;
}
inline void C2S::clear_has_filterconditions() {
  _has_bits_[0] &= ~0x00000002u;
}
inline const ::Trd_Common::TrdFilterConditions& C2S::filterconditions() const {
  const ::Trd_Common::TrdFilterConditions* p = filterconditions_;
  // @@protoc_insertion_point(field_get:Trd_GetHistoryOrderFillList.C2S.filterConditions)
  return p != NULL ? *p : *reinterpret_cast<const ::Trd_Common::TrdFilterConditions*>(
      &::Trd_Common::_TrdFilterConditions_default_instance_);
}
inline ::Trd_Common::TrdFilterConditions* C2S::release_filterconditions() {
  // @@protoc_insertion_point(field_release:Trd_GetHistoryOrderFillList.C2S.filterConditions)
  clear_has_filterconditions();
  ::Trd_Common::TrdFilterConditions* temp = filterconditions_;
  filterconditions_ = NULL;
  return temp;
}
inline ::Trd_Common::TrdFilterConditions* C2S::mutable_filterconditions() {
  set_has_filterconditions();
  if (filterconditions_ == NULL) {
    filterconditions_ = new ::Trd_Common::TrdFilterConditions;
  }
  // @@protoc_insertion_point(field_mutable:Trd_GetHistoryOrderFillList.C2S.filterConditions)
  return filterconditions_;
}
inline void C2S::set_allocated_filterconditions(::Trd_Common::TrdFilterConditions* filterconditions) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete reinterpret_cast< ::google::protobuf::MessageLite*>(filterconditions_);
  }
  if (filterconditions) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      filterconditions = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, filterconditions, submessage_arena);
    }
    set_has_filterconditions();
  } else {
    clear_has_filterconditions();
  }
  filterconditions_ = filterconditions;
  // @@protoc_insertion_point(field_set_allocated:Trd_GetHistoryOrderFillList.C2S.filterConditions)
}

// -------------------------------------------------------------------

// S2C

// required .Trd_Common.TrdHeader header = 1;
inline bool S2C::has_header() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void S2C::set_has_header() {
  _has_bits_[0] |= 0x00000001u;
}
inline void S2C::clear_has_header() {
  _has_bits_[0] &= ~0x00000001u;
}
inline const ::Trd_Common::TrdHeader& S2C::header() const {
  const ::Trd_Common::TrdHeader* p = header_;
  // @@protoc_insertion_point(field_get:Trd_GetHistoryOrderFillList.S2C.header)
  return p != NULL ? *p : *reinterpret_cast<const ::Trd_Common::TrdHeader*>(
      &::Trd_Common::_TrdHeader_default_instance_);
}
inline ::Trd_Common::TrdHeader* S2C::release_header() {
  // @@protoc_insertion_point(field_release:Trd_GetHistoryOrderFillList.S2C.header)
  clear_has_header();
  ::Trd_Common::TrdHeader* temp = header_;
  header_ = NULL;
  return temp;
}
inline ::Trd_Common::TrdHeader* S2C::mutable_header() {
  set_has_header();
  if (header_ == NULL) {
    header_ = new ::Trd_Common::TrdHeader;
  }
  // @@protoc_insertion_point(field_mutable:Trd_GetHistoryOrderFillList.S2C.header)
  return header_;
}
inline void S2C::set_allocated_header(::Trd_Common::TrdHeader* header) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete reinterpret_cast< ::google::protobuf::MessageLite*>(header_);
  }
  if (header) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      header = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, header, submessage_arena);
    }
    set_has_header();
  } else {
    clear_has_header();
  }
  header_ = header;
  // @@protoc_insertion_point(field_set_allocated:Trd_GetHistoryOrderFillList.S2C.header)
}

// repeated .Trd_Common.OrderFill orderFillList = 2;
inline int S2C::orderfilllist_size() const {
  return orderfilllist_.size();
}
inline const ::Trd_Common::OrderFill& S2C::orderfilllist(int index) const {
  // @@protoc_insertion_point(field_get:Trd_GetHistoryOrderFillList.S2C.orderFillList)
  return orderfilllist_.Get(index);
}
inline ::Trd_Common::OrderFill* S2C::mutable_orderfilllist(int index) {
  // @@protoc_insertion_point(field_mutable:Trd_GetHistoryOrderFillList.S2C.orderFillList)
  return orderfilllist_.Mutable(index);
}
inline ::Trd_Common::OrderFill* S2C::add_orderfilllist() {
  // @@protoc_insertion_point(field_add:Trd_GetHistoryOrderFillList.S2C.orderFillList)
  return orderfilllist_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::Trd_Common::OrderFill >*
S2C::mutable_orderfilllist() {
  // @@protoc_insertion_point(field_mutable_list:Trd_GetHistoryOrderFillList.S2C.orderFillList)
  return &orderfilllist_;
}
inline const ::google::protobuf::RepeatedPtrField< ::Trd_Common::OrderFill >&
S2C::orderfilllist() const {
  // @@protoc_insertion_point(field_list:Trd_GetHistoryOrderFillList.S2C.orderFillList)
  return orderfilllist_;
}

// -------------------------------------------------------------------

// Request

// required .Trd_GetHistoryOrderFillList.C2S c2s = 1;
inline bool Request::has_c2s() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Request::set_has_c2s() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Request::clear_has_c2s() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Request::clear_c2s() {
  if (c2s_ != NULL) c2s_->Clear();
  clear_has_c2s();
}
inline const ::Trd_GetHistoryOrderFillList::C2S& Request::c2s() const {
  const ::Trd_GetHistoryOrderFillList::C2S* p = c2s_;
  // @@protoc_insertion_point(field_get:Trd_GetHistoryOrderFillList.Request.c2s)
  return p != NULL ? *p : *reinterpret_cast<const ::Trd_GetHistoryOrderFillList::C2S*>(
      &::Trd_GetHistoryOrderFillList::_C2S_default_instance_);
}
inline ::Trd_GetHistoryOrderFillList::C2S* Request::release_c2s() {
  // @@protoc_insertion_point(field_release:Trd_GetHistoryOrderFillList.Request.c2s)
  clear_has_c2s();
  ::Trd_GetHistoryOrderFillList::C2S* temp = c2s_;
  c2s_ = NULL;
  return temp;
}
inline ::Trd_GetHistoryOrderFillList::C2S* Request::mutable_c2s() {
  set_has_c2s();
  if (c2s_ == NULL) {
    c2s_ = new ::Trd_GetHistoryOrderFillList::C2S;
  }
  // @@protoc_insertion_point(field_mutable:Trd_GetHistoryOrderFillList.Request.c2s)
  return c2s_;
}
inline void Request::set_allocated_c2s(::Trd_GetHistoryOrderFillList::C2S* c2s) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete c2s_;
  }
  if (c2s) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      c2s = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, c2s, submessage_arena);
    }
    set_has_c2s();
  } else {
    clear_has_c2s();
  }
  c2s_ = c2s;
  // @@protoc_insertion_point(field_set_allocated:Trd_GetHistoryOrderFillList.Request.c2s)
}

// -------------------------------------------------------------------

// Response

// required int32 retType = 1 [default = -400];
inline bool Response::has_rettype() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Response::set_has_rettype() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Response::clear_has_rettype() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Response::clear_rettype() {
  rettype_ = -400;
  clear_has_rettype();
}
inline ::google::protobuf::int32 Response::rettype() const {
  // @@protoc_insertion_point(field_get:Trd_GetHistoryOrderFillList.Response.retType)
  return rettype_;
}
inline void Response::set_rettype(::google::protobuf::int32 value) {
  set_has_rettype();
  rettype_ = value;
  // @@protoc_insertion_point(field_set:Trd_GetHistoryOrderFillList.Response.retType)
}

// optional string retMsg = 2;
inline bool Response::has_retmsg() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Response::set_has_retmsg() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Response::clear_has_retmsg() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Response::clear_retmsg() {
  retmsg_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_retmsg();
}
inline const ::std::string& Response::retmsg() const {
  // @@protoc_insertion_point(field_get:Trd_GetHistoryOrderFillList.Response.retMsg)
  return retmsg_.GetNoArena();
}
inline void Response::set_retmsg(const ::std::string& value) {
  set_has_retmsg();
  retmsg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Trd_GetHistoryOrderFillList.Response.retMsg)
}
#if LANG_CXX11
inline void Response::set_retmsg(::std::string&& value) {
  set_has_retmsg();
  retmsg_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Trd_GetHistoryOrderFillList.Response.retMsg)
}
#endif
inline void Response::set_retmsg(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_retmsg();
  retmsg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Trd_GetHistoryOrderFillList.Response.retMsg)
}
inline void Response::set_retmsg(const char* value, size_t size) {
  set_has_retmsg();
  retmsg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Trd_GetHistoryOrderFillList.Response.retMsg)
}
inline ::std::string* Response::mutable_retmsg() {
  set_has_retmsg();
  // @@protoc_insertion_point(field_mutable:Trd_GetHistoryOrderFillList.Response.retMsg)
  return retmsg_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Response::release_retmsg() {
  // @@protoc_insertion_point(field_release:Trd_GetHistoryOrderFillList.Response.retMsg)
  clear_has_retmsg();
  return retmsg_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Response::set_allocated_retmsg(::std::string* retmsg) {
  if (retmsg != NULL) {
    set_has_retmsg();
  } else {
    clear_has_retmsg();
  }
  retmsg_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), retmsg);
  // @@protoc_insertion_point(field_set_allocated:Trd_GetHistoryOrderFillList.Response.retMsg)
}

// optional int32 errCode = 3;
inline bool Response::has_errcode() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Response::set_has_errcode() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Response::clear_has_errcode() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Response::clear_errcode() {
  errcode_ = 0;
  clear_has_errcode();
}
inline ::google::protobuf::int32 Response::errcode() const {
  // @@protoc_insertion_point(field_get:Trd_GetHistoryOrderFillList.Response.errCode)
  return errcode_;
}
inline void Response::set_errcode(::google::protobuf::int32 value) {
  set_has_errcode();
  errcode_ = value;
  // @@protoc_insertion_point(field_set:Trd_GetHistoryOrderFillList.Response.errCode)
}

// optional .Trd_GetHistoryOrderFillList.S2C s2c = 4;
inline bool Response::has_s2c() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Response::set_has_s2c() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Response::clear_has_s2c() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Response::clear_s2c() {
  if (s2c_ != NULL) s2c_->Clear();
  clear_has_s2c();
}
inline const ::Trd_GetHistoryOrderFillList::S2C& Response::s2c() const {
  const ::Trd_GetHistoryOrderFillList::S2C* p = s2c_;
  // @@protoc_insertion_point(field_get:Trd_GetHistoryOrderFillList.Response.s2c)
  return p != NULL ? *p : *reinterpret_cast<const ::Trd_GetHistoryOrderFillList::S2C*>(
      &::Trd_GetHistoryOrderFillList::_S2C_default_instance_);
}
inline ::Trd_GetHistoryOrderFillList::S2C* Response::release_s2c() {
  // @@protoc_insertion_point(field_release:Trd_GetHistoryOrderFillList.Response.s2c)
  clear_has_s2c();
  ::Trd_GetHistoryOrderFillList::S2C* temp = s2c_;
  s2c_ = NULL;
  return temp;
}
inline ::Trd_GetHistoryOrderFillList::S2C* Response::mutable_s2c() {
  set_has_s2c();
  if (s2c_ == NULL) {
    s2c_ = new ::Trd_GetHistoryOrderFillList::S2C;
  }
  // @@protoc_insertion_point(field_mutable:Trd_GetHistoryOrderFillList.Response.s2c)
  return s2c_;
}
inline void Response::set_allocated_s2c(::Trd_GetHistoryOrderFillList::S2C* s2c) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete s2c_;
  }
  if (s2c) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      s2c = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, s2c, submessage_arena);
    }
    set_has_s2c();
  } else {
    clear_has_s2c();
  }
  s2c_ = s2c;
  // @@protoc_insertion_point(field_set_allocated:Trd_GetHistoryOrderFillList.Response.s2c)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Trd_GetHistoryOrderFillList

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Trd_5fGetHistoryOrderFillList_2eproto__INCLUDED
