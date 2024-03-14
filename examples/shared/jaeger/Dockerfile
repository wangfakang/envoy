FROM jaegertracing/all-in-one@sha256:13a5b3a876f6ec084d053ae4eed2b8501317de92cfbe93ad735c1316f41d72ab
HEALTHCHECK \
    --interval=1s \
    --timeout=1s \
    --start-period=1s \
    --retries=60 \
    CMD wget -q --header='Content-Type:application/json' -O - http://localhost:14269/health | grep "Server available"
