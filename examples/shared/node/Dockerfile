FROM node:23.0-bullseye-slim@sha256:fdc2b7008436408e4e7bbacd945c3ab1f5bb42134d4e44a10cdb68b317a3f592 as node-base


FROM node-base as node-http-auth
ARG NODE_APP=.
ARG NODE_APP_NAME=http-service/server
# Add an env to save ARG
ENV NODE_APP_PATH "/app/${NODE_APP_NAME}"
COPY "$NODE_APP" /app
# Dont use exec form to interpolate correctly
CMD node $NODE_APP_PATH
