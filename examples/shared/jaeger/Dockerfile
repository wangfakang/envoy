FROM jaegertracing/all-in-one@sha256:447d3ea59c6cba0c8689a96414fd832420131be5d50d26cf9946d95ba2a0f739
HEALTHCHECK \
    --interval=1s \
    --timeout=1s \
    --start-period=1s \
    --retries=60 \
    CMD wget -q --header='Content-Type:application/json' -O - http://localhost:14269/health | grep "Server available"
