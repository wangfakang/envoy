FROM node:21.7-bullseye-slim@sha256:cfa357b2b0c37e66057525c0e8b06cf1cb54f9cb5534b401b0a587df794a25df as node-base


FROM node-base as node-http-auth
ARG NODE_APP=.
ARG NODE_APP_NAME=http-service/server
# Add an env to save ARG
ENV NODE_APP_PATH "/app/${NODE_APP_NAME}"
COPY "$NODE_APP" /app
# Dont use exec form to interpolate correctly
CMD node $NODE_APP_PATH
