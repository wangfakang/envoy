#pragma once

#include "envoy/http/filter.h"
#include "envoy/upstream/cluster_manager.h"
#include "extensions/filters/http/golang_extention/golang_extention.h"

#include "common/grpc/context_impl.h"

namespace Envoy {
namespace Extensions {
namespace HttpFilters {
namespace GolangExtention {
/**
 * See docs/configuration/http_filters/golang_extention_filter.rst
 */
class ExtentionFilter : public Http::StreamFilter {
public:
  explicit ExtentionFilter(Grpc::Context& context) : context_(context) {}

  // Http::StreamFilterBase
  void onDestroy() override;

  // Http::StreamDecoderFilter
  Http::FilterHeadersStatus decodeHeaders(Http::RequestHeaderMap& headers,
                                          bool end_stream) override;
  Http::FilterDataStatus decodeData(Buffer::Instance&, bool) override;
  Http::FilterTrailersStatus decodeTrailers(Http::RequestTrailerMap&) override;
  void setDecoderFilterCallbacks(Http::StreamDecoderFilterCallbacks& ) override {
    //decoder_callbacks_ = &callbacks;
  }

  Http::FilterHeadersStatus encodeHeaders(Http::ResponseHeaderMap& headers,
                                          bool end_stream) override;
  Http::FilterDataStatus encodeData(Buffer::Instance& data, bool end_stream) override;
  Http::FilterTrailersStatus encodeTrailers(Http::ResponseTrailerMap& trailers) override;
  Http::FilterMetadataStatus encodeMetadata(Http::MetadataMap&) override {
    return Http::FilterMetadataStatus::Continue;
  }

  void setEncoderFilterCallbacks(Http::StreamEncoderFilterCallbacks&) override {
    //encoder_callbacks_ = &callbacks;
  }
  
  // Http::StreamEncoderFilter
  Http::FilterHeadersStatus encode100ContinueHeaders(Http::ResponseHeaderMap&) override {
    return Http::FilterHeadersStatus::Continue;
  }


private:
  Grpc::Context& context_;
  bool endstream;
};

} // namespace GolangExtention
} // namespace HttpFilters
} // namespace Extensions
} // namespace Envoy
