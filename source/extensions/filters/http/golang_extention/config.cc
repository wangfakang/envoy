#include "extensions/filters/http/golang_extention/config.h"

#include "envoy/registry/registry.h"

#include "extensions/filters/http/golang_extention/golang_extention_filter.h"

namespace Envoy {
namespace Extensions {
namespace HttpFilters {
namespace GolangExtention {

Http::FilterFactoryCb GolangExtentionFilterConfig::createFilterFactoryFromProtoTyped(
    const envoy::extensions::filters::http::golang_extention::v3::Config&, const std::string&,
    Server::Configuration::FactoryContext& factory_context) {
  return [&factory_context](Http::FilterChainFactoryCallbacks& callbacks) {
    callbacks.addStreamFilter(std::make_shared<ExtentionFilter>(factory_context.grpcContext()));
  };
}

/**
 * Static registration for the grpc HTTP1 bridge filter. @see RegisterFactory.
 */
REGISTER_FACTORY(GolangExtentionFilterConfig, Server::Configuration::NamedHttpFilterConfigFactory);

} // namespace GolangExtention
} // namespace HttpFilters
} // namespace Extensions
} // namespace Envoy
