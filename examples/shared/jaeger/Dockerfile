FROM jaegertracing/all-in-one@sha256:a46eac68a8b5d95563c7970d77d7eada7feab2ceca1d8a92c1fb6fa006a941f7
HEALTHCHECK \
    --interval=1s \
    --timeout=1s \
    --start-period=1s \
    --retries=60 \
    CMD wget -q --header='Content-Type:application/json' -O - http://localhost:14269/health | grep "Server available"
