FROM node:23.5-bullseye-slim@sha256:19436f9dd870d799f16258de43fb5bf4b90340f56f2232515d80d8f7908dc3d2 as node-base


FROM node-base as node-http-auth
ARG NODE_APP=.
ARG NODE_APP_NAME=http-service/server
# Add an env to save ARG
ENV NODE_APP_PATH "/app/${NODE_APP_NAME}"
COPY "$NODE_APP" /app
# Dont use exec form to interpolate correctly
CMD node $NODE_APP_PATH
