/*
Copyright 2020 Esri

Licensed under the Apache License, Version 2.0 (the "License"); you may not use
this file except in compliance with the License. You may obtain a copy of
the License at http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License.

For additional information, contact:
Environmental Systems Research Institute, Inc.
Attn: Contracts Dept
380 New York Street
Redlands, California, USA 92373
email: contracts@esri.com
*/

#pragma once 
// --------------------------------------
// file generated by test/scripts/enum_serialize.py 
// WARNING: EDITS WILL BE LOST !!
// --------------------------------------

I3S_EXPORT std::string     to_string(Alpha_mode enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Alpha_mode* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Alpha_mode& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Alpha_mode& me);


I3S_EXPORT std::string     to_string(Face_culling_mode enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Face_culling_mode* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Face_culling_mode& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Face_culling_mode& me);


I3S_EXPORT std::string     to_string(Type enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Type* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Type& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Type& me);


I3S_EXPORT std::string     to_string(Esri_field_type enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Esri_field_type* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Esri_field_type& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Esri_field_type& me);


I3S_EXPORT std::string     to_string(Legacy_topology enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Legacy_topology* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Legacy_topology& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Legacy_topology& me);


I3S_EXPORT std::string     to_string(Vertex_attrib_ordering enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Vertex_attrib_ordering* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Vertex_attrib_ordering& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Vertex_attrib_ordering& me);


I3S_EXPORT std::string     to_string(Feature_attrib_ordering enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Feature_attrib_ordering* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Feature_attrib_ordering& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Feature_attrib_ordering& me);


I3S_EXPORT std::string     to_string(Geometry_header_property enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Geometry_header_property* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Geometry_header_property& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Geometry_header_property& me);


I3S_EXPORT std::string     to_string(Mesh_topology enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Mesh_topology* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Mesh_topology& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Mesh_topology& me);


I3S_EXPORT std::string     to_string(Encoding enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Encoding* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Encoding& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Encoding& me);


I3S_EXPORT std::string     to_string(Lod_metric_type enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Lod_metric_type* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Lod_metric_type& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Lod_metric_type& me);


I3S_EXPORT std::string     to_string(Layer_type enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Layer_type* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Layer_type& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Layer_type& me);


I3S_EXPORT std::string     to_string(VB_Binding enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, VB_Binding* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const VB_Binding& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, VB_Binding& me);


I3S_EXPORT std::string     to_string(Texture_filtering_mode enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Texture_filtering_mode* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Texture_filtering_mode& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Texture_filtering_mode& me);


I3S_EXPORT std::string     to_string(Texture_wrap_mode enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Texture_wrap_mode* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Texture_wrap_mode& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Texture_wrap_mode& me);


I3S_EXPORT std::string     to_string(Normal_reference_frame enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Normal_reference_frame* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Normal_reference_frame& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Normal_reference_frame& me);


I3S_EXPORT std::string     to_string(Compressed_mesh_attribute enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Compressed_mesh_attribute* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Compressed_mesh_attribute& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Compressed_mesh_attribute& me);


I3S_EXPORT std::string     to_string(Attrib_header_property enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Attrib_header_property* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Attrib_header_property& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Attrib_header_property& me);


I3S_EXPORT std::string     to_string(Attrib_ordering enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Attrib_ordering* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Attrib_ordering& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Attrib_ordering& me);


I3S_EXPORT std::string     to_string(Compressed_geometry_format enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Compressed_geometry_format* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Compressed_geometry_format& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Compressed_geometry_format& me);


I3S_EXPORT std::string     to_string(Legacy_image_channel enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Legacy_image_channel* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Legacy_image_channel& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Legacy_image_channel& me);


I3S_EXPORT std::string     to_string(Legacy_wrap_mode enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Legacy_wrap_mode* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Legacy_wrap_mode& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Legacy_wrap_mode& me);


I3S_EXPORT std::string     to_string(Mime_image_format enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Mime_image_format* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Mime_image_format& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Mime_image_format& me);


I3S_EXPORT std::string     to_string(Legacy_uv_set enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Legacy_uv_set* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Legacy_uv_set& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Legacy_uv_set& me);


I3S_EXPORT std::string     to_string(Value_encoding enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Value_encoding* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Value_encoding& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Value_encoding& me);


I3S_EXPORT std::string     to_string(Attribute_storage_info_encoding enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Attribute_storage_info_encoding* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Attribute_storage_info_encoding& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Attribute_storage_info_encoding& me);


I3S_EXPORT std::string     to_string(Bsl_filter_mode enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Bsl_filter_mode* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Bsl_filter_mode& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Bsl_filter_mode& me);


I3S_EXPORT std::string     to_string(Height_model enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Height_model* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Height_model& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Height_model& me);


I3S_EXPORT std::string     to_string(Height_unit enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Height_unit* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Height_unit& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Height_unit& me);


I3S_EXPORT std::string     to_string(Continuity enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Continuity* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Continuity& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Continuity& me);


I3S_EXPORT std::string     to_string(Base_quantity enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Base_quantity* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Base_quantity& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Base_quantity& me);


I3S_EXPORT std::string     to_string(Statistics_status enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Statistics_status* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Statistics_status& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Statistics_status& me);


I3S_EXPORT std::string     to_string(Pcsl_attribute_buffer_type enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Pcsl_attribute_buffer_type* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Pcsl_attribute_buffer_type& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Pcsl_attribute_buffer_type& me);


I3S_EXPORT std::string     to_string(Bounding_volume_type enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Bounding_volume_type* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Bounding_volume_type& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Bounding_volume_type& me);


I3S_EXPORT std::string     to_string(Vxl_variable_semantic enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Vxl_variable_semantic* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Vxl_variable_semantic& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Vxl_variable_semantic& me);


I3S_EXPORT std::string     to_string(Vertical_exag_mode enum_val);
I3S_EXPORT bool            from_string(const std::string& txt_utf8, Vertical_exag_mode* out);
I3S_EXPORT utl::Archive_out& operator&(utl::Archive_out& ar, const Vertical_exag_mode& me);
I3S_EXPORT utl::Archive_in& operator&(utl::Archive_in& ar, Vertical_exag_mode& me);

