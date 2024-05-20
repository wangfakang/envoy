FROM jaegertracing/all-in-one@sha256:28ec4b341a44d616f8befb7a4c4fa0aafb31add67edabc39fd6eb3ac2e23feba
HEALTHCHECK \
    --interval=1s \
    --timeout=1s \
    --start-period=1s \
    --retries=60 \
    CMD wget -q --header='Content-Type:application/json' -O - http://localhost:14269/health | grep "Server available"
