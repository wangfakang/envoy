FROM node:22.1-bullseye-slim@sha256:3fd44a8648f66c1713cceb4e10087546fc7c4a040abf1e3c75406a17e5032fea as node-base


FROM node-base as node-http-auth
ARG NODE_APP=.
ARG NODE_APP_NAME=http-service/server
# Add an env to save ARG
ENV NODE_APP_PATH "/app/${NODE_APP_NAME}"
COPY "$NODE_APP" /app
# Dont use exec form to interpolate correctly
CMD node $NODE_APP_PATH
