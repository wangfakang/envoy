FROM node:23.11-bullseye-slim@sha256:4e9e317f7bbdc97a88fe0428f10861958462d11d09fa450cf74818993fbda8bb as node-base


FROM node-base as node-http-auth
ARG NODE_APP=.
ARG NODE_APP_NAME=http-service/server
# Add an env to save ARG
ENV NODE_APP_PATH "/app/${NODE_APP_NAME}"
COPY "$NODE_APP" /app
# Dont use exec form to interpolate correctly
CMD node $NODE_APP_PATH
