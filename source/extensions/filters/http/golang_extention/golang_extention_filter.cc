#include "extensions/filters/http/golang_extention/golang_extention_filter.h"

#include <cstdint>
#include <string>
#include <vector>

#include "envoy/http/codes.h"

#include "common/common/enum_to_int.h"
#include "common/common/utility.h"
#include "common/grpc/common.h"
#include "common/grpc/context_impl.h"
#include "common/http/headers.h"
#include "common/http/http1/codec_impl.h"

namespace Envoy {
namespace Extensions {
namespace HttpFilters {
namespace GolangExtention {

void ExtentionFilter::onDestroy() {
    // destroy phase of stream filter
}

Http::FilterHeadersStatus ExtentionFilter::decodeHeaders(Http::RequestHeaderMap& headers, bool end_stream) {
//  const bool grpc_request = Grpc::Common::isGrpcRequestHeaders(headers);
    if (!end_stream) {
        //return Http::FilterHeadersStatus::Continue;
    }

    int i = 0;
    Request reqbefore,reqafter;

    memset(&reqbefore, 0, sizeof(reqbefore));
    memset(&reqafter, 0, sizeof(reqafter));

    // build cgo struct
    headers.iterate([&reqbefore,&i](const Http::HeaderEntry& entry) -> Http::HeaderMap::Iterate {
        reqbefore.header_key[i] = strdup(std::string(entry.key().getStringView()).c_str());
        reqbefore.header_val[i] = strdup(std::string(entry.value().getStringView()).c_str());
        i++;
        return Http::HeaderMap::Iterate::Continue;
    });    

    // call golang stream filter 
    reqafter = updateHeader(reqbefore);

    for(i = 0; i < sizeof(reqafter.header_key) / sizeof(char*); i++) {
        if (reqafter.header_key[i] == NULL) {
            break;
        }
        
        if (reqafter.header_val[i] != NULL && strcmp(reqafter.header_val[i],"") == 0) {
            headers.remove(Http::LowerCaseString(reqafter.header_key[i]));

        } else {
            headers.remove(Http::LowerCaseString(reqafter.header_key[i]));
            headers.addCopy(Http::LowerCaseString(reqafter.header_key[i]), reqafter.header_val[i]);
        }

        // free memory
        free(const_cast<char *>(reqafter.header_key[i]));
        free(const_cast<char *>(reqafter.header_val[i]));
        free(const_cast<char *>(reqbefore.header_key[i]));
        free(const_cast<char *>(reqbefore.header_val[i]));
    }

    return Http::FilterHeadersStatus::Continue;
}

Http::FilterDataStatus ExtentionFilter::decodeData(Buffer::Instance&, bool end_stream) {
    if (!end_stream) {
        return Http::FilterDataStatus::Continue;
    }

    // call golang stream filter

    return Http::FilterDataStatus::Continue;
}

Http::FilterTrailersStatus ExtentionFilter::decodeTrailers(Http::RequestTrailerMap& ) {
    //printf("de 000000000000000003\n");
    return Http::FilterTrailersStatus::Continue;
}

Http::FilterHeadersStatus ExtentionFilter::encodeHeaders(Http::ResponseHeaderMap& , bool end_stream) {
    if (!end_stream) {
        return Http::FilterHeadersStatus::Continue;
    }

    // call golang append filter
    //printf("en 000000000000000001\n");
    return Http::FilterHeadersStatus::Continue;
}

Http::FilterDataStatus ExtentionFilter::encodeData(Buffer::Instance&, bool end_stream) {
    if (!end_stream) {
        return Http::FilterDataStatus::Continue;
    }

    // call golang append filter
    //printf("en 000000000000000003\n");
    return Http::FilterDataStatus::Continue;
}

Http::FilterTrailersStatus ExtentionFilter::encodeTrailers(Http::ResponseTrailerMap& ) {
    //printf("en 000000000000000004\n");
    return Http::FilterTrailersStatus::Continue;
}

} // namespace GolangExtention
} // namespace HttpFilters
} // namespace Extensions
} // namespace Envoy
