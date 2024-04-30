FROM node:22.0-bullseye-slim@sha256:e0110bf0d381c3dd1d3e9d14190f7a1940a861122fcb228c1473fa065f168529 as node-base


FROM node-base as node-http-auth
ARG NODE_APP=.
ARG NODE_APP_NAME=http-service/server
# Add an env to save ARG
ENV NODE_APP_PATH "/app/${NODE_APP_NAME}"
COPY "$NODE_APP" /app
# Dont use exec form to interpolate correctly
CMD node $NODE_APP_PATH
