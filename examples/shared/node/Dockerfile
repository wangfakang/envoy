FROM node:23.8-bullseye-slim@sha256:23f14061bdb69ec7ae04a292e8de122c57dcc58712bf8ce09c25180197e8d945 as node-base


FROM node-base as node-http-auth
ARG NODE_APP=.
ARG NODE_APP_NAME=http-service/server
# Add an env to save ARG
ENV NODE_APP_PATH "/app/${NODE_APP_NAME}"
COPY "$NODE_APP" /app
# Dont use exec form to interpolate correctly
CMD node $NODE_APP_PATH
