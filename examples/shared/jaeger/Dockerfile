FROM jaegertracing/all-in-one@sha256:041582ec588e0b95ae426a52d0752767a61b07a3ff669ebcb3097edc39489cf8
HEALTHCHECK \
    --interval=1s \
    --timeout=1s \
    --start-period=1s \
    --retries=60 \
    CMD wget -q --header='Content-Type:application/json' -O - http://localhost:14269/health | grep "Server available"
