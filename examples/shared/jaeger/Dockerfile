FROM jaegertracing/all-in-one@sha256:fcb6553200e46bce88b4a3c4d743496a77c53bf9131beec1372e862a8fd75d88
HEALTHCHECK \
    --interval=1s \
    --timeout=1s \
    --start-period=1s \
    --retries=60 \
    CMD wget -q --header='Content-Type:application/json' -O - http://localhost:14269/health | grep "Server available"
