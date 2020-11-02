#pragma once

#include "envoy/extensions/filters/http/golang_extention/v3/config.pb.h"
#include "envoy/extensions/filters/http/golang_extention/v3/config.pb.validate.h"

#include "extensions/filters/http/common/factory_base.h"
#include "extensions/filters/http/well_known_names.h"

namespace Envoy {
namespace Extensions {
namespace HttpFilters {
namespace GolangExtention {

/**
 * Config registration for the grpc HTTP1 bridge filter. @see NamedHttpFilterConfigFactory.
 */
class GolangExtentionFilterConfig
    : public Common::FactoryBase<envoy::extensions::filters::http::golang_extention::v3::Config> {
public:
  GolangExtentionFilterConfig() : FactoryBase(HttpFilterNames::get().GolangExtention) {}

  Http::FilterFactoryCb createFilterFactoryFromProtoTyped(
      const envoy::extensions::filters::http::golang_extention::v3::Config& proto_config,
      const std::string& stats_prefix,
      Server::Configuration::FactoryContext& factory_context) override;
};

} // namespace GolangExtention
} // namespace HttpFilters
} // namespace Extensions
} // namespace Envoy
