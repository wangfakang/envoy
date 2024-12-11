FROM node:23.4-bullseye-slim@sha256:7f9a5ee2d95c39c6f4b8025bcc89d8ff90b13d8814f6b5ec9baf837373f108e0 as node-base


FROM node-base as node-http-auth
ARG NODE_APP=.
ARG NODE_APP_NAME=http-service/server
# Add an env to save ARG
ENV NODE_APP_PATH "/app/${NODE_APP_NAME}"
COPY "$NODE_APP" /app
# Dont use exec form to interpolate correctly
CMD node $NODE_APP_PATH
