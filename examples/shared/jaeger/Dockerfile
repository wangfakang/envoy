FROM jaegertracing/all-in-one@sha256:2794799f8307b4857690bad51debb00e40448bb9757a3e9ffdc9aad3378b4c61
HEALTHCHECK \
    --interval=1s \
    --timeout=1s \
    --start-period=1s \
    --retries=60 \
    CMD wget -q --header='Content-Type:application/json' -O - http://localhost:14269/health | grep "Server available"
