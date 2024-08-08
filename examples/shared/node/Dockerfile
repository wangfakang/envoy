FROM node:22.6-bullseye-slim@sha256:eb1ad26a330802dcbbc9e2b8f2de9a7c807613442947f1ba966498621a7841c9 as node-base


FROM node-base as node-http-auth
ARG NODE_APP=.
ARG NODE_APP_NAME=http-service/server
# Add an env to save ARG
ENV NODE_APP_PATH "/app/${NODE_APP_NAME}"
COPY "$NODE_APP" /app
# Dont use exec form to interpolate correctly
CMD node $NODE_APP_PATH
